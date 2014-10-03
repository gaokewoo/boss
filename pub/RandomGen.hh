#ifndef __RANDOMGEN__
#define __RANDOMGEN__
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <stdio.h>
#include <map>
#include "Name.hh"

using namespace std;

typedef struct 
{
    string id;
    string name;
    string gender;
    string addr;
    string region_nbr;
    string fax_nbr;
    string tel_nbr;
    string post_code;
    string email_addr;
}RandomInfo;

class RandomGen
{
public:
    RandomGen();
    string getAddress();
    map<int,string> getAllAddress();
    string getID();
    string getNbr();
    string getName();
    RandomInfo getRandomInfo();
    int getRandomInt(int refer);

private:
   map<int,string> id; 
   Name name;
};

#endif

