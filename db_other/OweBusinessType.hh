#ifndef __OWEBUSINESSTYPE__
#define __OWEBUSINESSTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweBusinessType:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_OWE_BUSINESS_TYPE> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_OWE_BUSINESS_TYPE owe_business_type;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_OWE_BUSINESS_TYPE> v_data;
    static string insSQL;
};
#endif
