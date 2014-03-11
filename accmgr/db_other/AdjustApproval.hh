#ifndef __ADJUSTAPPROVAL__
#define __ADJUSTAPPROVAL__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AdjustApproval:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ADJUST_APPROVAL adjust_approval;

private:
    static string insSQL;
};
#endif
