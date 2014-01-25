#ifndef __PRIVILEGE__
#define __PRIVILEGE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Privilege:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_PRIVILEGE> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_PRIVILEGE privilege;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_PRIVILEGE> v_data;
    static string insSQL;
};
#endif
