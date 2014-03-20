#ifndef __ADJUSTACCTITEM_HH__
#define __ADJUSTACCTITEM_HH__

#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "OracleDB.hh"
#include "DBStruct.hh"
#include "log4z/log4z.h"
#include "Sequence.hh"
#include "BillingCycle.hh"
#include "Staff.hh"
#include "Region.hh"
#include "StaffOpr.hh"
#include "ServIdentification.hh"
#include "ServAcct.hh"
#include "AcctItemType.hh"
#include "AcctItemSource.hh"
#include "AcctItem.hh"
#include "AcctItemAdjusted.hh"
#include "ChargeAdjustLog.hh"
#include "Acct.hh"
#include "Dual.hh"

using namespace zsummer::log4z;

class AdjustAcctItemData{
    public:
        AdjustAcctItemData():nbr(""),ym(""),fee(0.00){}

        string nbr;
        string ym;
        double fee;
};

class AdjustAcctItem
{
public:
    AdjustAcctItem(LoggerId logId);
    ~AdjustAcctItem();
    void loadConfigData();
    void doBiz(AdjustAcctItemData & data);

private:
    LoggerId m_logId;
    OracleDB *m_db;
    Sequence m_seq;

    vector<ST_BILLING_CYCLE> v_billing_cycle; 
    vector<ST_STAFF> v_staff; 
    vector<ST_REGION> v_region; 
    vector<ST_ACCT_ITEM_TYPE> v_acct_item_type; 
};

#endif

