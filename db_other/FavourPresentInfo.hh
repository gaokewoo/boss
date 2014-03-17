#ifndef __FAVOURPRESENTINFO__
#define __FAVOURPRESENTINFO__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class FavourPresentInfo:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_FAVOUR_PRESENT_INFO favour_present_info;

private:
    static string insSQL;
};
#endif
