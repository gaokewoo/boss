#ifndef __CHNACCCREDITDET__
#define __CHNACCCREDITDET__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ChnAccCreditDet:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CHN_ACC_CREDIT_DET chn_acc_credit_det;

private:
    static string insSQL;
};
#endif
