#include <iostream>
#include "RandomGen.hh"

int main()
{
    using namespace std;

    RandomGen id;

    for(int i=0;i<10;i++)
        cout<<id.getID()<<endl;

    for(int i=0;i<10;i++)
        cout<<id.getNbr()<<endl;

    for(int i=0;i<10;i++)
        cout<<id.getName()<<endl;

    for(int i=0;i<10;i++)
        cout<<id.getAddress()<<endl;

    RandomInfo tmp;
    for(int i=0;i<10;i++)
    {
        tmp = id.getRandomInfo();
        cout<<"---------------------------"<<endl;
        cout<<tmp.id<<endl;
        cout<<tmp.name<<endl;
        cout<<tmp.gender<<endl;
        cout<<tmp.addr<<endl;
        cout<<tmp.region_nbr<<endl;
        cout<<tmp.fax_nbr<<endl;
        cout<<tmp.tel_nbr<<endl;
        cout<<tmp.post_code<<endl;
        cout<<tmp.email_addr<<endl;
        cout<<"---------------------------\n"<<endl;
    }

    return 0;
}
