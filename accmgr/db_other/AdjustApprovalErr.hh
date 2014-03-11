#ifndef __ADJUSTAPPROVALERR__
#define __ADJUSTAPPROVALERR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class AdjustApprovalErr:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_ADJUST_APPROVAL_ERR adjust_approval_err;

private:
    static string insSQL;
};
#endif
