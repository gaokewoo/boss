#ifndef __REGION__
#define __REGION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Region:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_REGION> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_REGION region;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_REGION> v_data;
    static string insSQL;
};
#endif
