#ifndef __PAYCARDOPR__
#define __PAYCARDOPR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class PayCardOpr:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PAY_CARD_OPR pay_card_opr;

private:
    static string insSQL;
};
#endif
