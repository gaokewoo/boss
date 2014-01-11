#ifndef __PHONECOMM__
#define __PHONECOMM__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PhoneComm:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PHONE_COMM phone_comm;

private:
    static string insSQL;
};
#endif
