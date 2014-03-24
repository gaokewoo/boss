#ifndef __SERV__
#define __SERV__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class Serv:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse();
    ST_SERV getServByServId(long serv_id);
    void updateStateInServByServId(long serv_id,string state);

public:
    ST_SERV serv;

private:
    static string insSQL;
    enum OP_TYPE {INSERT=0,UPDATE,SELECT_BY_SERV_ID};
    OP_TYPE type;
    long m_serv_id;
    string m_state;
};
#endif
