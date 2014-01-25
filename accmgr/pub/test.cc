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

    return 0;
}
