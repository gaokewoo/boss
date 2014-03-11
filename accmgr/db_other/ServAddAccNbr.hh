#ifndef __SERVADDACCNBR__
#define __SERVADDACCNBR__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServAddAccNbr:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_ADD_ACC_NBR serv_add_acc_nbr;

private:
    static string insSQL;
};
#endif
