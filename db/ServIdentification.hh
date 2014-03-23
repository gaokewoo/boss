#ifndef __SERVIDENTIFICATION__
#define __SERVIDENTIFICATION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServIdentification:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse();
    ST_SERV_IDENTIFICATION getRandomServIdentInfo();
    ST_SERV_IDENTIFICATION getServIdentInfoByNBR(string nbr);
    ST_SERV_IDENTIFICATION getServIdentInfoByServId(long serv_id);

public:
    ST_SERV_IDENTIFICATION serv_identification;

private:
    enum OP_TYPE{INS=0,SEL_RANDOM,SEL_BY_NBR,SEL_BY_SERV_ID};
    OP_TYPE op_type;
    string my_nbr;
    long m_serv_id;
    static string insSQL;
};
#endif
