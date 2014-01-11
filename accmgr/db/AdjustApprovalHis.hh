#ifndef __ADJUSTAPPROVALHIS__
#define __ADJUSTAPPROVALHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AdjustApprovalHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ADJUST_APPROVAL_HIS adjust_approval_his;

private:
    static string insSQL;
};
#endif
