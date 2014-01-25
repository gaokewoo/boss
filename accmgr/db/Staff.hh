#ifndef __STAFF__
#define __STAFF__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Staff:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_STAFF> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_STAFF staff;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_STAFF> v_data;
    static string insSQL;
};
#endif
