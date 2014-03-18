#ifndef __PAYFEE_HH__
#define __PAYFEE_HH__

#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "OracleDB.hh"
#include "DBStruct.hh"
#include "Sequence.hh"
#include "log4z/log4z.h"

using namespace zsummer::log4z;

class PayFeeData{
    public:
        PayFeeData():nbr(""),fee(0.00){}

        string nbr;
        double fee;
};

class PayFee
{
public:
    PayFee(LoggerId logId);
    ~PayFee();
    void doBiz(PayFeeData & data);

private:
    LoggerId m_logId;
    OracleDB *m_db;

};

#endif

