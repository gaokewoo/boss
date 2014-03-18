#ifndef __CONFIGDATA_HH__
#define __CONFIGDATA_HH__

#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "OracleDB.hh"
#include "DBStruct.hh"
#include "Sequence.hh"
#include "CertificateType.hh"
#include "AcctType.hh"
#include "Privilege.hh"
#include "StaffPrivilege.hh"
#include "Staff.hh"
#include "Region.hh"
#include "BillingRegion.hh"
#include "Name.hh"
#include "RandomGen.hh"
#include "Address.hh"
#include "BillingCycle.hh"
#include "BillingCycleType.hh"
#include "ServStateDesc.hh"
#include "PaymentMethod.hh"
#include "BalanceSourceType.hh"
#include "BalanceType.hh"
#include "AcctItemType.hh"
#include "AcctItemSource.hh"
#include "log4z/log4z.h"

using namespace zsummer::log4z;
class ConfigData
{
public:
    ConfigData(LoggerId logId);
    ~ConfigData();
    void configCertificateType();
    void configAcctType();
    void configPrivilegeAndStaff();
    void configRegionAndBillingRegion();
    void configAddress();
    void configBillingCycle();
    void configServStateDesc();
    void configPaymentMethodAndBalanceType();
    void configBalanceSourceType();
    void configAcctItemTypeAndAcctItemSource();
    void doBiz();

private:
    LoggerId m_logId;
    OracleDB *m_db;

    Sequence m_seq;
    CertificateType m_certificate_type;
    AcctType m_acct_type;
    Privilege m_privilege;
    Staff m_staff;
    StaffPrivilege m_staff_privilege;
    Region m_region;
    BillingRegion m_billing_region;
    Address m_address;
    BillingCycle m_billing_cycle;
    BillingCycleType m_billing_cycle_type;
    ServStateDesc m_serv_state_desc;
    PaymentMethod m_payment_method;
    BalanceSourceType m_balance_source_type;
    BalanceType m_balance_type;
    AcctItemType m_acct_item_type;
    AcctItemSource m_acct_item_source;
};

#endif

