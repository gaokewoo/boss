#ifndef __DUAL__
#define __DUAL__
#include "SQLInterface.hh"

class Dual:public SQLInterface
{
public:
    string getSysDateYYYYMM();
    string getSysDateYYYYMMDD();
    string getSysDateYYYYMMDDHH24MISS();
    virtual void doParse();

public:

private:
    string data;
};
#endif
