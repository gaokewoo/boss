#ifndef __ACCTITEM__
#define __ACCTITEM__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AcctItem:public SQLInterface
{
public:
    AcctItem();
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};
    void setYM(string ym){m_ym = ym;}

public:
    ST_ACCT_ITEM acct_item;

private:
    string m_ym;
};
#endif
