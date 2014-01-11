#ifndef __PRODUCT__
#define __PRODUCT__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Product:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRODUCT product;

private:
    static string insSQL;
};
#endif
