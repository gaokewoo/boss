#ifndef __FAVOURPRESENTINFOADD__
#define __FAVOURPRESENTINFOADD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class FavourPresentInfoAdd:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_FAVOUR_PRESENT_INFO_ADD favour_present_info_add;

private:
    static string insSQL;
};
#endif
