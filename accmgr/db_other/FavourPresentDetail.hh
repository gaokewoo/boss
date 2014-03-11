#ifndef __FAVOURPRESENTDETAIL__
#define __FAVOURPRESENTDETAIL__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class FavourPresentDetail:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_FAVOUR_PRESENT_DETAIL favour_present_detail;

private:
    static string insSQL;
};
#endif
