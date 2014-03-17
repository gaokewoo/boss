#ifndef __ADJUSTAPPROVALTOTAL__
#define __ADJUSTAPPROVALTOTAL__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AdjustApprovalTotal:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ADJUST_APPROVAL_TOTAL adjust_approval_total;

private:
    static string insSQL;
};
#endif
