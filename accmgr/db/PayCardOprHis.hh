#ifndef __PAYCARDOPRHIS__
#define __PAYCARDOPRHIS__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PayCardOprHis:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PAY_CARD_OPR_HIS pay_card_opr_his;

private:
    static string insSQL;
};
#endif
