#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include "gen-cpp/AdjustAcctItem.h"
#include "libconfparser/confparser.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstdio>
 
using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using boost::shared_ptr;

string getRandomYM(int year,int month)
{
    int tmp_year, tmp_month;

    struct tm *times;
    time_t t;

    t = time(0);

    times = localtime(&t);

    int cur_year=times->tm_year+1900;
    int cur_month=times->tm_mon+1;

    if(cur_year<=year)
    {
        year=cur_year;
    }

    if(cur_year==year && cur_month<=month)
    {
        month=cur_month;
    }

    if(cur_year==year && cur_month==month)
    {
        tmp_year=year;
        tmp_month=month;
    }
    else
    {
        int step=(cur_year-year)*12+(cur_month-month);
        int value=rand()%(step+1);

        tmp_year=year+(month+value)/12;
        tmp_month=(month+value)%12;
        if(tmp_month==0)
        {
            tmp_year-=1;
            tmp_month=12;
        }
    }

    char tmp[10]={'\0'};
    sprintf(tmp,"%d%02d",tmp_year,tmp_month);

    return tmp;
}


int main(int argc, char** argv) {   

    CONF_PARSER_SIMPLE_INIT("../conf/boss.cfg");
    int port = CONF_PARSER_GET_NUM_VAL("AdjustAcctItem", "port");
    const char* pval = CONF_PARSER_GET_VAL("AdjustAcctItem", "ip");
    cout<<"Server IP:"<<pval<<" Port:"<<port<<endl;

    int frequence = CONF_PARSER_GET_NUM_VAL("AdjustAcctItem", "frequence");
    cout<<"The client send request each "<<frequence<<" millisecond."<<endl;

    int start_ym = CONF_PARSER_GET_NUM_VAL("AdjustAcctItem", "start_ym");
    cout<<"Adjust acct item start ym: "<<start_ym<<endl;

    int specify_ym = CONF_PARSER_GET_NUM_VAL("AdjustAcctItem", "specify_ym");
    cout<<"Adjust acct item specify ym: "<<specify_ym<<endl;

    int year=start_ym/100;
    int month=start_ym%100;

    if(year<2013)
    {
        cout<<"The year value must bigger than 2013."<<endl;

        exit(-1);
    }

    if(month<1||month>12)
    {
        cout<<"The month value:"<<month<<" error."<<endl;

        exit(-1);
    }

    shared_ptr<TTransport> socket(new TSocket(pval, port));   

    shared_ptr<TTransport> transport(new TBufferedTransport(socket));   

    shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));   

    BossInterface::AdjustAcctItemClient  client(protocol);   

    try {  
        int i=0;
        transport->open();

        srand( (unsigned)time( NULL ) );

        BossData::AdjustAcctItem data;

        while(1)
        {
            cout<<"----------["<<++i<<"]----------"<<endl;

            if(specify_ym!=0)
            {
                char tmp[10]={'\0'};
                sprintf(tmp,"%d",specify_ym);
                data.ym=tmp;
            }
            else
            {
                data.ym=getRandomYM(year,month);
            }

            client.send(data);

            usleep(frequence*1000);
        }

        transport->close();   

    } catch (TException &tx) {
        transport->close();   
        cerr<<"ERROR: "<<tx.what()<<endl;   
    }

}  
