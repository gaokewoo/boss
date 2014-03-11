#ifndef __NBRIMSI__
#define __NBRIMSI__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class NbrImsi:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_NBR_IMSI nbr_imsi;

private:
    static string insSQL;
};
#endif
