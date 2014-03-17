#ifndef __CUSTCONTACTINFO__
#define __CUSTCONTACTINFO__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CustContactInfo:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CUST_CONTACT_INFO cust_contact_info;

private:
    static string insSQL;
};
#endif
