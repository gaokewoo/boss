#include "WriteOff.hh"
#include "libconfparser/confparser.hpp"
#include "BillInterface.hh"
#include "Acct.hh"
#include "Dual.hh"
#include "AcctItem.hh"
#include "AcctBalance.hh"
#include "AcctItemSource.hh"

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
    LOG_DEBUG(m_logId, "WriteOff::doBiz start");

    Dual dual;
    dual.setConnection(m_db->getConnection());
    string ym = dual.getSysDateYYYYMM();
    LOG_INFO(m_logId, "WriteOff::doBiz current ym:"<<ym);

    BillInterface m_bill_interface;
    m_bill_interface.setConnection(m_db->getConnection());
    vector<ST_BILL_INTERFACE> v_bill_interface(m_bill_interface.loadAllData());

    for(vector<ST_BILL_INTERFACE>::iterator it=v_bill_interface.begin();
                it != v_bill_interface.end(); it++)
    {
        long payment_id = (*it).m_payment_id;
        long acct_id = (*it).m_acct_id;
        LOG_INFO(m_logId, "WriteOff::doBiz get acct info by acct_id:"<<acct_id);
        Acct m_acct;
        m_acct.setConnection(m_db->getConnection());
        ST_ACCT acct_data = m_acct.getAcctByAcctId(acct_id);
        LOG_INFO(m_logId, "WriteOff::doBiz acct_id:"<<acct_id<<" owe_min_ym:"<<acct_data.m_owe_min_ym<<" owe_fee:"<<acct_data.m_owe_fee);

        if(acct_data.m_owe_fee <= 0)
        {
            LOG_INFO(m_logId,"No owe fee, no need to do write-off.");

            continue;
        }

        long owe_min_ym = acct_data.m_owe_min_ym;

        LOG_INFO(m_logId, "WriteOff::doBiz get acct balance info by acct_id:"<<acct_id);
        AcctBalance m_acct_balance;
        m_acct_balance.setConnection(m_db->getConnection());
        vector<ST_ACCT_BALANCE> v_acct_balance(m_acct_balance.getAcctBalanceByAcctId(acct_id));

        for(vector<ST_ACCT_BALANCE>::iterator it=v_acct_balance.begin();
                    it != v_acct_balance.end(); )
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

                AcctItem m_acct_item;
                m_acct_item.setConnection(m_db->getConnection());
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

                        LOG_INFO(m_logId, "AdjustAcctItem::doBiz update ACCT_ITEM table");
                        m_acct_item.updateStateAndAmountInAcctItemByAcctItemId(acct_item_id,"5JB",amount);
                    }
                    else
                    {
                        amount-=balance;
                        pay_out_balance += balance;
                        used_balance=balance;

                        //split acct_item status;
                        LOG_INFO(m_logId, "AdjustAcctItem::doBiz update ACCT_ITEM table");
                        m_acct_item.updateStateAndAmountInAcctItemByAcctItemId(acct_item_id,"5JB",balance);

                        LOG_INFO(m_logId, "AdjustAcctItem::doBiz insert to ACCT_ITEM_SOURCE table");
                        AcctItemSource m_acct_item_source;
                        m_acct_item_source.setConnection(m_db->getConnection());
                        long item_source_id=m_seq.getItemSourceId();
                        m_acct_item_source.acct_item_source.m_item_source_id=item_source_id;
                        m_acct_item_source.acct_item_source.m_acct_item_type_id=(*it).m_acct_item_type_id;
                        m_acct_item_source.acct_item_source.m_item_source_type="52A";
                        m_acct_item_source.acct_item_source.m_name="帐目应收费用";
                        m_acct_item_source.acct_item_source.m_comments="新增";
                        m_acct_item_source.insertData();

                        LOG_INFO(m_logId, "AdjustAcctItem::doBiz insert to acct_item table");
                        long acct_item_id=m_seq.getAcctItemId();
                        m_acct_item.acct_item.m_acct_item_id=acct_item_id;
                        m_acct_item.acct_item.m_item_source_id=item_source_id;
                        m_acct_item.acct_item.m_bill_id=0;
                        m_acct_item.acct_item.m_acct_item_type_id=(*it).m_acct_item_type_id;
                        m_acct_item.acct_item.m_billing_cycle_id=(*it).m_billing_cycle_id;
                        m_acct_item.acct_item.m_acct_id=(*it).m_acct_id;
                        m_acct_item.acct_item.m_serv_id=(*it).m_serv_id;
                        m_acct_item.acct_item.m_amount=amount;
                        m_acct_item.acct_item.m_fee_cycle_id=(*it).m_billing_cycle_id;
                        m_acct_item.acct_item.m_payment_method=0;
                        m_acct_item.acct_item.m_state="00A";
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

                    //fill BALANCE_ACCT_ITEM_PAYEDYYYYMM*****
                    
                    if(balance <= 0)
                    {
                        break;
                    }
                }

                //update acct owe_min_ym and owe_fee=owe_fee-balance_out
                long owe_fee = acct_data.m_owe_fee-pay_out_balance;
                LOG_INFO(m_logId, "AdjustAcctItem::doBiz acct_id:"<<acct_id<<" new owe_min_ym:"<<owe_min_ym<<"  owe_fee:"<<owe_fee);
                m_acct.setAcctOweMinYMAndOweFee(acct_id,owe_min_ym,owe_fee);

                owe_min_ym=getNextYm(owe_min_ym);
            }

            if(balance <= 0)
            {
                //mv to his
                LOG_INFO(m_logId, "WriteOff::doBiz acct balance id:"<<acct_balance_id<<" balance equals 0, mv to his");
                //m_acct_balance.deleteAcctBalanceByAcctBalanceId(acct_balance_id);*****
            }
            else
            {
                //update acct_balance balance****
            }
            //fill balance_payout*****
            //fill balance_log*****
        }

        //fill BILLYYYYMM*****
        LOG_INFO(m_logId, "WriteOff::doBiz mv from bill_interface to bill_interface_his for payment_id:"<<payment_id);
        BillInterface m_bill_interface;
        //m_bill_interface.deleteBillInterfaceByPaymentId(payment_id); *****
    }
    LOG_DEBUG(m_logId, "WriteOff::doBiz end");

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


