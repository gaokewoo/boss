#include "WriteOff.hh"
#include "libconfparser/confparser.hpp"
#include "BillInterface.hh"
#include "Acct.hh"
#include "Dual.hh"
#include "AcctItem.hh"
#include "AcctBalance.hh"
#include "AcctItemSource.hh"
#include "BalanceAcctItemPayed.hh"
#include "BalancePayout.hh"
#include "AcctBalanceLog.hh"
#include "Bill.hh"
#include "BillingCycle.hh"
#include "ServIdentification.hh"

WriteOff::WriteOff(LoggerId logId)
{
    m_logId = logId;
    LOG_DEBUG(m_logId, "WriteOff::WriteOff start");

    LOG_DEBUG(logId, "Parse boss.cfg");
    CONF_PARSER_SIMPLE_INIT("../conf/boss.cfg");
    string db_user = CONF_PARSER_GET_VAL("DB", "user");
    string db_passwd = CONF_PARSER_GET_VAL("DB", "passwd");
    string db_instance = CONF_PARSER_GET_VAL("DB", "instance");
    LOG_DEBUG(logId, "DB User:"<<db_user);
    LOG_DEBUG(logId, "DB Passwd:"<<db_passwd);
    LOG_DEBUG(logId, "DB Instance:"<<db_instance);

    m_db = new OracleDB(db_user,db_passwd,db_instance);
    m_db->connectToDB();

    m_seq.setConnection(m_db->getConnection());

    LOG_DEBUG(m_logId, "WriteOff::WriteOff end");
}

WriteOff::~WriteOff()
{
    LOG_DEBUG(m_logId, "WriteOff::~WriteOff start");
    m_db->disConnectFromDB();
    LOG_DEBUG(m_logId, "WriteOff::~WriteOff end");
}

void WriteOff::doBiz()
{
    try
    {
        LOG_DEBUG(m_logId, "WriteOff::doBiz start");
        Dual dual;
        dual.setConnection(m_db->getConnection());
        string ym = dual.getSysDateYYYYMM();
        LOG_INFO(m_logId, "WriteOff::doBiz current ym:"<<ym);

        Acct m_acct;
        m_acct.setConnection(m_db->getConnection());

        AcctBalance m_acct_balance;
        m_acct_balance.setConnection(m_db->getConnection());

        AcctItem m_acct_item;
        m_acct_item.setConnection(m_db->getConnection());

        AcctItemSource m_acct_item_source;
        m_acct_item_source.setConnection(m_db->getConnection());

        BalanceAcctItemPayed m_balance_acct_item_payed;
        m_balance_acct_item_payed.setConnection(m_db->getConnection());

        BalancePayout m_balance_payout;
        m_balance_payout.setConnection(m_db->getConnection());

        AcctBalanceLog m_acct_balance_log;
        m_acct_balance_log.setConnection(m_db->getConnection());

        BillingCycle m_billing_cycle;
        m_billing_cycle.setConnection(m_db->getConnection());
        vector<ST_BILLING_CYCLE> v_billing_cycle = m_billing_cycle.getEffectiveBillingCycle();
        long billing_cycle_id = 0;
        if (!v_billing_cycle.empty())
        {
            billing_cycle_id = v_billing_cycle[0].m_billing_cycle_id;
        }

        ServIdentification m_serv_ident;
        m_serv_ident.setConnection(m_db->getConnection());

        Bill m_bill;
        m_bill.setConnection(m_db->getConnection());

        BillInterface m_bill_interface;
        m_bill_interface.setConnection(m_db->getConnection());
        vector<ST_BILL_INTERFACE> v_bill_interface(m_bill_interface.loadAllData());

        for(vector<ST_BILL_INTERFACE>::iterator it=v_bill_interface.begin();
                    it != v_bill_interface.end(); it++)
        {
            long payment_id = (*it).m_payment_id;
            long acct_id = (*it).m_acct_id;
            long payment_method = (*it).m_payment_method;
            long serv_id= (*it).m_serv_id;
            long bill_balance=0;
            long bill_id = m_seq.getBillId();
            LOG_INFO(m_logId, "WriteOff::doBiz get acct info by acct_id:"<<acct_id);
            ST_ACCT acct_data = m_acct.getAcctByAcctId(acct_id);
            LOG_INFO(m_logId, "WriteOff::doBiz acct_id:"<<acct_id<<" owe_min_ym:"<<acct_data.m_owe_min_ym<<" owe_fee:"<<acct_data.m_owe_fee);

            if(acct_data.m_owe_fee <= 0)
            {
                LOG_INFO(m_logId,"No owe fee, no need to do write-off.");
                m_bill_interface.deleteBillInterfaceByPaymentId(payment_id);

                continue;
            }

            long owe_min_ym = acct_data.m_owe_min_ym;

            LOG_INFO(m_logId, "WriteOff::doBiz get acct balance info by acct_id:"<<acct_id);
            vector<ST_ACCT_BALANCE> v_acct_balance(m_acct_balance.getAcctBalanceByAcctId(acct_id));

            for(vector<ST_ACCT_BALANCE>::iterator it=v_acct_balance.begin();
                        it != v_acct_balance.end(); it++)
            {
                long acct_balance_id = (*it).m_acct_balance_id;
                long balance = (*it).m_balance;
                long pay_out_balance = 0;
                LOG_INFO(m_logId, "WriteOff::doBiz acct balance id:"<<acct_balance_id<<" balance:"<<balance);

                if(owe_min_ym > atol(ym.c_str()))
                  break;

                long oper_payout_id = m_seq.getOperPayoutId();
                while(owe_min_ym <= atol(ym.c_str()))
                {
                    LOG_INFO(m_logId, "WriteOff::doBiz get acct_item info by acct_id:"<<acct_id<<" and owe_min_ym:"<<owe_min_ym);

                    if(balance <= 0)
                    {
                        break;
                    }

                    char tmp[30];
                    sprintf(tmp,"%ld",owe_min_ym);
                    m_acct_item.setYM(tmp);
                    vector<ST_ACCT_ITEM> v_acct_item(m_acct_item.getAcctItemByAcctId(acct_id));

                    for(vector<ST_ACCT_ITEM>::iterator it=v_acct_item.begin();
                                it != v_acct_item.end(); it++)
                    {
                        long acct_item_id = (*it).m_acct_item_id;
                        long amount = (*it).m_amount;
                        LOG_INFO(m_logId, "WriteOff::doBiz acct item id:"<<acct_item_id<<" amount:"<<amount);

                        long used_balance=0;
                        if(balance >= amount)
                        {
                            balance-=amount;
                            pay_out_balance += amount;
                            used_balance=amount;

                            LOG_INFO(m_logId, "WriteOff::doBiz update ACCT_ITEM table");
                            m_acct_item.updateStateAndAmountInAcctItemByAcctItemId(acct_item_id,"5JB",amount);
                        }
                        else
                        {
                            amount-=balance;
                            pay_out_balance += balance;
                            used_balance=balance;
                            balance=0;

                            //split acct_item status;
                            LOG_INFO(m_logId, "WriteOff::doBiz update ACCT_ITEM table");
                            m_acct_item.updateStateAndAmountInAcctItemByAcctItemId(acct_item_id,"5JB",balance);

                            LOG_INFO(m_logId, "WriteOff::doBiz insert to ACCT_ITEM_SOURCE table");
                            long item_source_id=m_seq.getItemSourceId();
                            m_acct_item_source.acct_item_source.m_item_source_id=item_source_id;
                            m_acct_item_source.acct_item_source.m_acct_item_type_id=(*it).m_acct_item_type_id;
                            m_acct_item_source.acct_item_source.m_item_source_type="52A";
                            m_acct_item_source.acct_item_source.m_name="帐目应收费用";
                            m_acct_item_source.acct_item_source.m_comments="新增";
                            m_acct_item_source.insertData();

                            LOG_INFO(m_logId, "WriteOff::doBiz insert to acct_item table");
                            long acct_item_id=m_seq.getAcctItemId();
                            m_acct_item.acct_item.m_acct_item_id=acct_item_id;
                            m_acct_item.acct_item.m_item_source_id=item_source_id;
                            m_acct_item.acct_item.m_bill_id=0;
                            m_acct_item.acct_item.m_acct_item_type_id=(*it).m_acct_item_type_id;
                            m_acct_item.acct_item.m_billing_cycle_id=(*it).m_billing_cycle_id;
                            m_acct_item.acct_item.m_acct_id=(*it).m_acct_id;
                            m_acct_item.acct_item.m_serv_id=(*it).m_serv_id;
                            m_acct_item.acct_item.m_amount=amount;
                            m_acct_item.acct_item.m_fee_cycle_id=(*it).m_fee_cycle_id;
                            m_acct_item.acct_item.m_payment_method=payment_method;
                            m_acct_item.acct_item.m_state="5JA";
                            m_acct_item.acct_item.m_latn_id=(*it).m_latn_id;
                            m_acct_item.acct_item.m_ai_total_id=0;
                            m_acct_item.acct_item.m_acc_nbr=(*it).m_acc_nbr;
                            m_acct_item.acct_item.m_should_pay=amount;
                            m_acct_item.acct_item.m_favour_fee=0;
                            m_acct_item.acct_item.m_times=0;
                            m_acct_item.acct_item.m_duration=0;
                            m_acct_item.acct_item.m_month_wrtoff_fee=0;
                            m_acct_item.acct_item.m_pay_wrtoff_fee=0;
                            m_acct_item.acct_item.m_attr_code="";

                            m_acct_item.insertData();
                        }

                        //fill BALANCE_ACCT_ITEM_PAYEDYYYYMM
                        LOG_INFO(m_logId, "WriteOff::doBiz insert to table BALANCE_ACCT_ITEM_PAYEDYYYYMM");
                        m_balance_acct_item_payed.balance_acct_item_payed.m_oper_payout_id=oper_payout_id;
                        m_balance_acct_item_payed.balance_acct_item_payed.m_acct_item_id=(*it).m_acct_item_id;
                        m_balance_acct_item_payed.balance_acct_item_payed.m_balance=used_balance;
                        m_balance_acct_item_payed.balance_acct_item_payed.m_serv_id=(*it).m_serv_id;
                        m_balance_acct_item_payed.balance_acct_item_payed.m_acct_item_type_id=(*it).m_acct_item_type_id;
                        m_balance_acct_item_payed.balance_acct_item_payed.m_item_source_id=(*it).m_item_source_id;
                        m_balance_acct_item_payed.balance_acct_item_payed.m_state="00A";
                        m_balance_acct_item_payed.insertData();

                        if(balance <= 0)
                        {
                            break;
                        }
                    }

                    //update acct owe_min_ym and owe_fee=owe_fee-balance_out
                    long owe_fee = acct_data.m_owe_fee-pay_out_balance;
                    LOG_INFO(m_logId, "WriteOff::doBiz acct_id:"<<acct_id<<" new owe_min_ym:"<<owe_min_ym<<"  owe_fee:"<<owe_fee);
                    m_acct.setAcctOweMinYMAndOweFee(acct_id,owe_min_ym,owe_fee);

                    owe_min_ym=getNextYm(owe_min_ym);
                }

                if(balance <= 0)
                {
                    //mv to his
                    LOG_INFO(m_logId, "WriteOff::doBiz acct balance id:"<<acct_balance_id<<" balance equals 0, mv to his");
                    m_acct_balance.deleteAcctBalanceByAcctBalanceId(acct_balance_id);
                }
                else
                {
                    //update acct_balance balance
                    LOG_INFO(m_logId, "WriteOff::doBiz update acct_balance");
                    m_acct_balance.updateAcctBalanceByAcctBalanceId(acct_balance_id,balance);
                }
                //fill balance_payout
                LOG_INFO(m_logId, "WriteOff::doBiz fill balance_payout");
                m_balance_payout.balance_payout.m_oper_payout_id=oper_payout_id;
                m_balance_payout.balance_payout.m_acct_balance_id=acct_balance_id;
                m_balance_payout.balance_payout.m_billing_cycle_id=billing_cycle_id;
                m_balance_payout.balance_payout.m_bill_id=bill_id;
                m_balance_payout.balance_payout.m_oper_type="5UH";
                m_balance_payout.balance_payout.m_amount=pay_out_balance;
                m_balance_payout.balance_payout.m_balance=balance;
                m_balance_payout.balance_payout.m_prn_count=0;
                m_balance_payout.balance_payout.m_balance_relation_id=0;
                m_balance_payout.balance_payout.m_staff_id=9999;
                m_balance_payout.balance_payout.m_state="00A";
                m_balance_payout.insertData();

                //fill acct_balance_log*****
                LOG_INFO(m_logId, "WriteOff::doBiz fill acct_balance_log");
                m_acct_balance_log.acct_balance_log.m_balance_log_id=m_seq.getScardvcsn();
                m_acct_balance_log.acct_balance_log.m_acct_balance_id=(*it).m_acct_balance_id;
                m_acct_balance_log.acct_balance_log.m_oper_income_id=0;
                m_acct_balance_log.acct_balance_log.m_src_amount=0;
                m_acct_balance_log.acct_balance_log.m_oper_payout_id=oper_payout_id;
                m_acct_balance_log.acct_balance_log.m_payout_amount=pay_out_balance;
                m_acct_balance_log.acct_balance_log.m_billing_cycle_id=billing_cycle_id;
                m_acct_balance_log.acct_balance_log.m_state="00A";
                m_acct_balance_log.insertData();

                bill_balance+=pay_out_balance;
            }

            //get serv_identification info
            LOG_INFO(m_logId, "WriteOff::doBiz get serv_identification info by serv_id:"<<serv_id);
            ST_SERV_IDENTIFICATION serv_ident_info = m_serv_ident.getServIdentInfoByServId(serv_id);

            //fill BILLYYYYMM
            LOG_INFO(m_logId, "WriteOff::doBiz fill BILLYYYYMM");
            m_bill.bill.m_bill_id=bill_id;
            m_bill.bill.m_ai_total_id=0;
            m_bill.bill.m_payment_id=payment_id;
            m_bill.bill.m_payment_method=payment_method;
            m_bill.bill.m_billing_cycle_id=billing_cycle_id;
            m_bill.bill.m_party_role_id=9999;
            m_bill.bill.m_acct_id=acct_id;
            m_bill.bill.m_serv_id=serv_id;
            m_bill.bill.m_acc_nbr=serv_ident_info.m_acc_nbr;
            m_bill.bill.m_bill_amount=0;
            m_bill.bill.m_late_fee=0;
            m_bill.bill.m_derate_late_fee=0;
            m_bill.bill.m_balance=bill_balance;
            m_bill.bill.m_last_change=0;
            m_bill.bill.m_cur_change=0;
            m_bill.bill.m_use_derate_blance=0;
            m_bill.bill.m_invoice_id=0;
            m_bill.bill.m_state="5JA";
            m_bill.insertData();

            LOG_INFO(m_logId, "WriteOff::doBiz mv from bill_interface to bill_interface_his for payment_id:"<<payment_id);
            m_bill_interface.deleteBillInterfaceByPaymentId(payment_id);
        }
        m_db->commit();
        LOG_DEBUG(m_logId, "WriteOff::doBiz end");
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "WriteOff::doBiz error");
        m_db->rollback();
        exit(-1);
    }
}

long WriteOff::getNextYm(long owe_min_ym)
{
    long year = owe_min_ym/100;
    long month = owe_min_ym%100;

    if(++month >= 13)
    {
        year++;
        month-=12;
    }

    return year*100+month;
}


