#include "OracleDB.hh"
#include "DBStruct.hh"
#include "Sequence.hh"
#include "Serv.hh"
#include "Cust.hh"
#include "Acct.hh"
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "Name.hh"
#include "log4z/log4z.h"

using namespace zsummer::log4z;

int main()
{
    LoggerId open_account;
    ILog4zManager::GetInstance()->Config("../conf/log.cfg");
    open_account = ILog4zManager::GetInstance()->FindLogger("OpenAccount");
    ILog4zManager::GetInstance()->Start();
    //ILog4zManager::GetInstance()->SetLoggerDisplay(open_account, true);
    //ILog4zManager::GetInstance()->SetLoggerLevel(open_account, LOG_LEVEL_DEBUG);
    //ILog4zManager::GetInstance()->SetLoggerMonthdir(open_account, true);

    OracleDB *db = new OracleDB();
    db->connectToDB();

    Sequence seq;
    seq.setConnection(db->getConnection());

    Serv my_serv;
    my_serv.setConnection(db->getConnection());

    Cust my_cust;
    my_cust.setConnection(db->getConnection());

    Acct my_acct;
    my_acct.setConnection(db->getConnection());

    long region_id = seq.getRegionId();
    long agreement_id = seq.getAgreementId();
    long product_id = seq.getScardvcsn();
    long billing_cycle_type_id = seq.getScardvcsn();
    long band_id = seq.getScardvcsn();
    long party_id = seq.getPartyId();

    Name name;
    for(int i=0;i<50;i++)
    {
        long serv_id = seq.getServId();
        long acct_id = seq.getAcctId();
        long cust_id = seq.getCustId();
        long family_id = seq.getScardvcsn();
        long cust_location= seq.getScardvcsn();

        string my_name=name.getName();

        LOG_DEBUG(open_account, "LOG_DEBUG"<<" "<<my_name<<" "<<i);
        LOG_INFO(open_account, "LOG_INFO"<<" "<<my_name<<" "<<i);
        LOG_WARN(open_account, "LOG_WARN"<<" "<<my_name<<" "<<i);
        LOG_ERROR(open_account, "LOG_ERROR"<<" "<<my_name<<" "<<i);
        LOG_ALARM(open_account, "LOG_ALARM"<<" "<<my_name<<" "<<i);
        LOG_FATAL(open_account, "LOG_FATAL"<<" "<<my_name<<" "<<i);

        my_serv.serv.m_serv_id=serv_id;
        my_serv.serv.m_agreement_id=agreement_id;
        my_serv.serv.m_cust_id=acct_id;
        my_serv.serv.m_product_id=product_id;
        my_serv.serv.m_billing_cycle_type_id=billing_cycle_type_id;
        my_serv.serv.m_product_family_id=family_id;
        my_serv.serv.m_state="0";
        my_serv.serv.m_region_id=region_id;
        my_serv.serv.m_band_id=band_id;
        my_serv.insertData();

        my_cust.cust.m_cust_id=cust_id;
        my_cust.cust.m_party_role_id=party_id;
        my_cust.cust.m_cust_name=my_name;
        my_cust.cust.m_cust_type="01";
        my_cust.cust.m_cust_location=cust_location;
        my_cust.cust.m_is_vip="N";
        my_cust.cust.m_cust_code="A";
        my_cust.cust.m_state="0";
        my_cust.insertData();


        my_acct.acct.m_acct_id=acct_id;
        my_acct.acct.m_cust_id=cust_id;
        my_acct.acct.m_acct_name=my_name;
        my_acct.acct.m_address_id=seq.getAddressId();
        ;
        my_acct.acct.m_state="0";
        my_acct.acct.m_acct_pwd="&8re@31";
        my_acct.acct.m_region_id=region_id;
        my_acct.acct.m_acct_type="10";
        my_acct.acct.m_owe_min_ym=201401;
        my_acct.acct.m_owe_fee=0;
        my_acct.insertData();

        if(i%200==0) db->commit();
    }
    db->disConnectFromDB();
    return 0;
}
