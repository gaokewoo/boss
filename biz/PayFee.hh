#ifndef __PAYFEE_HH__
#define __PAYFEE_HH__

#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "OracleDB.hh"
#include "DBStruct.hh"
#include "Sequence.hh"
#include "PaymentMethod.hh"
#include "BalanceSourceType.hh"
#include "BalanceType.hh"
#include "BillingCycle.hh"
#include "Staff.hh"
#include "StaffOpr.hh"
#include "Region.hh"
#include "Payment.hh"
#include "ServAcct.hh"
#include "BalanceSource.hh"
#include "AcctBalance.hh"
#include "BillInterface.hh"
#include "log4z/log4z.h"
#include "cppzmq/zmq.hpp"

using namespace zsummer::log4z;

using namespace zmq;

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
    void loadConfigData();
    void doBiz(PayFeeData & data);

private:
    LoggerId m_logId;
    OracleDB *m_db;
    Sequence m_seq;

    vector<ST_PAYMENT_METHOD> v_payment_method; 
    vector<ST_BALANCE_SOURCE_TYPE> v_balance_source_type; 
    vector<ST_BALANCE_TYPE> v_balance_type; 
    vector<ST_BILLING_CYCLE> v_billing_cycle; 
    vector<ST_STAFF> v_staff; 
    vector<ST_REGION> v_region; 

    // Prepare our context and socket
    context_t *context;
    socket_t *socket;

};

#endif

