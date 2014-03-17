#ifndef __SERVADDACCNBRDEAD__
#define __SERVADDACCNBRDEAD__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ServAddAccNbrDead:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_SERV_ADD_ACC_NBR_DEAD serv_add_acc_nbr_dead;

private:
    static string insSQL;
};
#endif
