#ifndef __SERVSTATEDESC__
#define __SERVSTATEDESC__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServStateDesc:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_SERV_STATE_DESC> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_SERV_STATE_DESC serv_state_desc;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_SERV_STATE_DESC> v_data;
    static string insSQL;
};
#endif
