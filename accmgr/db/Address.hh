#ifndef __ADDRESS__
#define __ADDRESS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Address:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_ADDRESS> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_ADDRESS address;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_ADDRESS> v_data;
    static string insSQL;
};
#endif
