#include <iostream>
#include <stdlib.h>

using namespace std;
const int NUM=2000;

void genFiveDigitString()
{

    cout<<"const string a[]={";
    for(int i=0;i<NUM;i++)
    {
        cout<<"\""<<rand()%100000<<"\"";
        if(i<NUM-1)
          cout<<",";
        if(i%10==0)
          cout<<" \\"<<endl;
    }
    cout<<"};"<<endl;

}

void genFourdigitNum()
{
    cout<<"const int a[]={";
    for(int i=0;i<NUM;i++)
    {
        cout<<rand()%10000;
        if(i<NUM-1)
          cout<<",";
        if(i%10==0)
          cout<<" \\"<<endl;
    }
    cout<<"};"<<endl;
}

int main()
{
    //string a[]={"vc","vf","vz","vt","vb","vd","vw"};
    //cout<<sizeof(a)/sizeof(a[0])<<endl;
    srand( (unsigned)time( NULL ) ); 

    //genFiveDigitString();
    genFourdigitNum();
}
