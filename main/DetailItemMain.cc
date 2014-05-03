#include <iostream>
#include <string>
#include <signal.h>
#include "libconfparser/confparser.hpp"
#include "DetailItem.hh"

int frequence;
LoggerId logId;

void handler(int signo)
{
    cerr<<"Program terminated"<<endl;  
    exit(0);  
}

void *thread_func(void *)
{
    DetailItem *m_detail_item = new DetailItem(logId);

    while(1)
    {
        //cout<<"----------thread_id:"<<pthread_self()<<"["<<++i<<"]----------"<<endl;
        m_detail_item->doBiz();

        usleep(frequence*1000);
    }

    return 0;
}

int main(int argc, char** argv) {   

    ILog4zManager::GetInstance()->Config("../conf/log.cfg");
    logId = ILog4zManager::GetInstance()->FindLogger("DetailItem");
    ILog4zManager::GetInstance()->Start();

    CONF_PARSER_SIMPLE_INIT("../conf/boss.cfg");
    int thread_num = CONF_PARSER_GET_NUM_VAL("DetailItem", "thread_num");
    cout<<"Thread num:"<<thread_num<<endl;

    int frequence = CONF_PARSER_GET_NUM_VAL("DetailItem", "frequence");
    cout<<"The client send request each "<<frequence<<" milliseconds."<<endl;

    signal(SIGINT,handler);

    try 
    {

        pthread_t *threadArr=new pthread_t[thread_num];
        for(int i=0; i<thread_num; i++)
        {
            cout<<"Create thread:"<<i<<endl;
            pthread_create(&threadArr[i],NULL,thread_func,0);
        }

        for(int i=0; i<thread_num; i++)
        {
            pthread_join(threadArr[i],NULL);
        }

    }
    catch (...) 
    {   
        cerr<<"ERROR....."<<endl;
        exit(-1);
    }   

}
