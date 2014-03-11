#ifndef __FAVOURPRESENTRULE__
#define __FAVOURPRESENTRULE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class FavourPresentRule:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_FAVOUR_PRESENT_RULE favour_present_rule;

private:
    static string insSQL;
};
#endif
