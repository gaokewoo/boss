#ifndef __OPENACCOUNT_HH__
#define __OPENACCOUNT_HH__

#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "OracleDB.hh"
#include "DBStruct.hh"
#include "Sequence.hh"
#include "CertificateType.hh"
#include "AcctType.hh"
#include "Staff.hh"
#include "Region.hh"
#include "BillingRegion.hh"
#include "Name.hh"
#include "RandomGen.hh"
#include "Address.hh"
#include "BillingCycle.hh"
#include "ServStateDesc.hh"
#include "Serv.hh"
#include "Cust.hh"
#include "Acct.hh"
#include "CustContactInfo.hh"
#include "CustIdentification.hh"
#include "Agreement.hh"
#include "ServIdentification.hh"
#include "ServLocation.hh"
#include "ServStateAttr.hh"
#include "ServBillingMode.hh"
#include "StaffOpr.hh"
#include "ServAcct.hh"
#include "log4z/log4z.h"

using namespace zsummer::log4z;

class AccountData{
    public:
        AccountData():nbr(""),name(""),gender(""),idNo(""),address(""){}

        string nbr;
        string name;
        string gender;
        string idNo;
        string address;
};

class OpenAccount
{
public:
    OpenAccount(LoggerId logId);
    ~OpenAccount();
    void doBiz(AccountData & data);
    void loadConfigData();
    void resetDB();

private:
    LoggerId m_logId;
    OracleDB *m_db;

    RandomGen generator;
    Sequence m_seq;
    Serv m_serv;
    Cust m_cust;
    Acct m_acct;
    CustContactInfo m_cust_contact_info;
    CustIdentification m_cust_ident;
    Agreement m_agreement;
    ServIdentification m_serv_ident;
    ServLocation m_serv_location;
    ServStateAttr m_serv_state_attr;
    ServBillingMode m_serv_billing_mode;
    StaffOpr m_staff_opr;
    ServAcct m_serv_acct;

    vector<ST_CERTIFICATE_TYPE> v_certificate_type; 
    vector<ST_ACCT_TYPE> v_acct_type; 
    vector<ST_STAFF> v_staff; 
    vector<ST_REGION> v_region; 
    vector<ST_BILLING_REGION> v_billing_region; 
    vector<ST_ADDRESS> v_address; 
    vector<ST_BILLING_CYCLE> v_billing_cycle; 
    vector<ST_SERV_STATE_DESC> v_serv_state_desc; 

    int num;
};

#endif

