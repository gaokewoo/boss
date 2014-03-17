#ifndef __PAYMENT_HH__
#define __PAYMENT_HH__

#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "OracleDB.hh"
#include "DBStruct.hh"
#include "Sequence.hh"
#include "log4z/log4z.h"

using namespace zsummer::log4z;

class PaymentData{
    public:
        PaymentData():nbr(""),fee(0.00){}

        string nbr;
        double fee;
};

class Payment
{
public:
    Payment(LoggerId logId);
    ~Payment();
    void doBiz(PaymentData & data);

private:
    LoggerId m_logId;
    OracleDB *m_db;

};

#endif

