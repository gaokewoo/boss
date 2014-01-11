#ifndef __SERVPRODUCT__
#define __SERVPRODUCT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServProduct:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_PRODUCT serv_product;

private:
    static string insSQL;
};
#endif
