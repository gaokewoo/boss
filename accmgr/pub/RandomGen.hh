#ifndef __RANDOMGEN__
#define __RANDOMGEN__
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <stdio.h>
#include <map>
#include "Name.hh"

using namespace std;

class RandomGen
{
public:
    RandomGen();
    string getAddress();
    string getID();
    string getNbr();
    string getName();

private:
   map<int,string> id; 
   map<int,string> region; 
   Name name;
};

#endif

