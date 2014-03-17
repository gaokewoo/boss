#ifndef __NAME__
#define __NAME__
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <stdio.h>

using namespace std;

class Name
{
public:
    Name();
    string getFirstName();
    string getSecondName();
    string getName();

private:
    static const int first_size=215;
    static const int second_size=840;
};

#endif

