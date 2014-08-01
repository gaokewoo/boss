#include "AcctItem.hh"
#include "Dual.hh"

AcctItem::AcctItem()
{
    m_ym="";
}

void AcctItem::insertData()
{
    type=INSERT;
    if(m_ym == "")
    {
        Dual dual;
        dual.setConnection(conn);
        m_ym = dual.getSysDateYYYYMM();
    }
    string insSQL="INSERT INTO ACCT_ITEM"+m_ym+"(ACCT_ITEM_ID,ITEM_SOURCE_ID,BILL_ID,ACCT_ITEM_TYPE_ID,BILLING_CYCLE_ID,ACCT_ID,SERV_ID,AMOUNT,CREATED_DATE,FEE_CYCLE_ID,PAYMENT_METHOD,STATE,STATE_DATE,LATN_ID,AI_TOTAL_ID,ACC_NBR,SHOULD_PAY,FAVOUR_FEE,TIMES,DURATION,MONTH_WRTOFF_FEE,PAY_WRTOFF_FEE,ATTR_CODE)VALUES (:ACCT_ITEM_ID,:ITEM_SOURCE_ID,:BILL_ID,:ACCT_ITEM_TYPE_ID,:BILLING_CYCLE_ID,:ACCT_ID,:SERV_ID,:AMOUNT,SYSDATE,:FEE_CYCLE_ID,:PAYMENT_METHOD,:STATE,SYSDATE,:LATN_ID,:AI_TOTAL_ID,:ACC_NBR,:SHOULD_PAY,:FAVOUR_FEE,:TIMES,:DURATION,:MONTH_WRTOFF_FEE,:PAY_WRTOFF_FEE,:ATTR_CODE)";

    setSQL(insSQL);

    executeUpdate();
}

void AcctItem::updateStateAndAmountInAcctItemByAcctItemId(long acct_item_id,string state,long amount)
{
    type=UPDATE_STATE_AMOUNT;
    m_state=state;
    m_acct_item_id=acct_item_id;
    m_amount=amount;
    if(m_ym == "")
    {
        Dual dual;
        dual.setConnection(conn);
        m_ym = dual.getSysDateYYYYMM();
    }
    string insSQL="UPDATE ACCT_ITEM"+m_ym+" SET STATE=:STATE,AMOUNT=:AMOUNT WHERE ACCT_ITEM_ID=:ACCT_ITEM_ID";

    setSQL(insSQL);

    executeUpdate();
}

void AcctItem::updateOtherFeeInAcctItemByAcctItemId(long acct_item_id,long amount,long should_pay,long favour_fee)
{
    type=UPDATE_OTHER_FEE;
    m_acct_item_id=acct_item_id;
    m_amount=amount;
    m_should_pay=should_pay;
    m_favour_fee=favour_fee;
    if(m_ym == "")
    {
        Dual dual;
        dual.setConnection(conn);
        m_ym = dual.getSysDateYYYYMM();
    }
    string insSQL="UPDATE ACCT_ITEM"+m_ym+" SET AMOUNT=:AMOUNT,SHOULD_PAY=:SHOULD_PAY,FAVOUR_FEE=:FAVOUR_FEE WHERE ACCT_ITEM_ID=:ACCT_ITEM_ID";

    setSQL(insSQL);

    executeUpdate();
}

vector<ST_ACCT_ITEM> AcctItem::getAcctItemByAcctId(long acct_id)
{
    type=SELECT_BY_ACCT_ID;
    m_acct_id = acct_id;
    if(m_ym == "")
    {
        Dual dual;
        dual.setConnection(conn);
        m_ym = dual.getSysDateYYYYMM();
    }
    setSQL("SELECT ACCT_ITEM_ID,ITEM_SOURCE_ID,BILL_ID,ACCT_ITEM_TYPE_ID,BILLING_CYCLE_ID,ACCT_ID,SERV_ID,AMOUNT,TO_CHAR(CREATED_DATE,'YYYYMMDDHH24MISS'),FEE_CYCLE_ID,PAYMENT_METHOD,STATE,TO_CHAR(STATE_DATE,'YYYYMMDDHH24MISS'),LATN_ID,AI_TOTAL_ID,ACC_NBR,SHOULD_PAY,FAVOUR_FEE,TIMES,DURATION,MONTH_WRTOFF_FEE,PAY_WRTOFF_FEE,ATTR_CODE FROM ACCT_ITEM"+m_ym+" WHERE ACCT_ID=:ACCT_ID");
    executeQuery();

    return v_data;
}

ST_ACCT_ITEM AcctItem::getAcctItemByAcctIdServId(long acct_id,long serv_id,long acct_item_type_id,string state)
{
    type=SELECT_BY_ACCT_ID_SERV_ID;
    m_acct_id = acct_id;
    m_serv_id = serv_id;
    m_acct_item_type_id = acct_item_type_id;
    m_state = state;

    acct_item.m_acct_item_id=0;

    if(m_ym == "")
    {
        Dual dual;
        dual.setConnection(conn);
        m_ym = dual.getSysDateYYYYMM();
    }
    setSQL("SELECT ACCT_ITEM_ID,ITEM_SOURCE_ID,BILL_ID,ACCT_ITEM_TYPE_ID,BILLING_CYCLE_ID,ACCT_ID,SERV_ID,AMOUNT,TO_CHAR(CREATED_DATE,'YYYYMMDDHH24MISS'),FEE_CYCLE_ID,PAYMENT_METHOD,STATE,TO_CHAR(STATE_DATE,'YYYYMMDDHH24MISS'),LATN_ID,AI_TOTAL_ID,ACC_NBR,SHOULD_PAY,FAVOUR_FEE,TIMES,DURATION,MONTH_WRTOFF_FEE,PAY_WRTOFF_FEE,ATTR_CODE FROM ACCT_ITEM"+m_ym+" WHERE ACCT_ID=:ACCT_ID AND SERV_ID=:SERV_ID AND ACCT_ITEM_TYPE_ID=:ACCT_ITEM_TYPE_ID AND STATE=:STATE");
    executeQuery();

    return acct_item;
}

void AcctItem::doParse()
{
    if (type == SELECT_BY_ACCT_ID)
    {
        acct_item.m_acct_item_id = (long)rset->getNumber(1);
        acct_item.m_item_source_id = (long)rset->getNumber(2);
        acct_item.m_bill_id = (long)rset->getNumber(3);
        acct_item.m_acct_item_type_id = (long)rset->getNumber(4);
        acct_item.m_billing_cycle_id = (long)rset->getNumber(5);
        acct_item.m_acct_id = (long)rset->getNumber(6);
        acct_item.m_serv_id = (long)rset->getNumber(7);
        acct_item.m_amount = (long)rset->getNumber(8);
        acct_item.m_created_date = rset->getString(9);
        acct_item.m_fee_cycle_id = (long)rset->getNumber(10);
        acct_item.m_payment_method = (long)rset->getNumber(11);
        acct_item.m_state = rset->getString(12);
        acct_item.m_state_date = rset->getString(13);
        acct_item.m_latn_id = (long)rset->getNumber(14);
        acct_item.m_ai_total_id = (long)rset->getNumber(15);
        acct_item.m_acc_nbr = rset->getString(16);
        acct_item.m_should_pay = (long)rset->getNumber(17);
        acct_item.m_favour_fee = (long)rset->getNumber(18);
        acct_item.m_times = (long)rset->getNumber(19);
        acct_item.m_duration = (long)rset->getNumber(20);
        acct_item.m_month_wrtoff_fee = (long)rset->getNumber(21);
        acct_item.m_pay_wrtoff_fee = (long)rset->getNumber(22);
        acct_item.m_attr_code = rset->getString(23);

        v_data.push_back(acct_item);
    }
    else if (type == SELECT_BY_ACCT_ID_SERV_ID)
    {
        acct_item.m_acct_item_id = (long)rset->getNumber(1);
        acct_item.m_item_source_id = (long)rset->getNumber(2);
        acct_item.m_bill_id = (long)rset->getNumber(3);
        acct_item.m_acct_item_type_id = (long)rset->getNumber(4);
        acct_item.m_billing_cycle_id = (long)rset->getNumber(5);
        acct_item.m_acct_id = (long)rset->getNumber(6);
        acct_item.m_serv_id = (long)rset->getNumber(7);
        acct_item.m_amount = (long)rset->getNumber(8);
        acct_item.m_created_date = rset->getString(9);
        acct_item.m_fee_cycle_id = (long)rset->getNumber(10);
        acct_item.m_payment_method = (long)rset->getNumber(11);
        acct_item.m_state = rset->getString(12);
        acct_item.m_state_date = rset->getString(13);
        acct_item.m_latn_id = (long)rset->getNumber(14);
        acct_item.m_ai_total_id = (long)rset->getNumber(15);
        acct_item.m_acc_nbr = rset->getString(16);
        acct_item.m_should_pay = (long)rset->getNumber(17);
        acct_item.m_favour_fee = (long)rset->getNumber(18);
        acct_item.m_times = (long)rset->getNumber(19);
        acct_item.m_duration = (long)rset->getNumber(20);
        acct_item.m_month_wrtoff_fee = (long)rset->getNumber(21);
        acct_item.m_pay_wrtoff_fee = (long)rset->getNumber(22);
        acct_item.m_attr_code = rset->getString(23);
    }
}

void AcctItem::prepareSQL()
{
    if (type == INSERT)
    {
        stmt->setNumber(1,acct_item.m_acct_item_id);
        stmt->setNumber(2,acct_item.m_item_source_id);
        stmt->setNumber(3,acct_item.m_bill_id);
        stmt->setNumber(4,acct_item.m_acct_item_type_id);
        stmt->setNumber(5,acct_item.m_billing_cycle_id);
        stmt->setNumber(6,acct_item.m_acct_id);
        stmt->setNumber(7,acct_item.m_serv_id);
        stmt->setNumber(8,acct_item.m_amount);
        stmt->setNumber(9,acct_item.m_fee_cycle_id);
        stmt->setNumber(10,acct_item.m_payment_method);
        stmt->setString(11,acct_item.m_state);
        stmt->setNumber(12,acct_item.m_latn_id);
        stmt->setNumber(13,acct_item.m_ai_total_id);
        stmt->setString(14,acct_item.m_acc_nbr);
        stmt->setNumber(15,acct_item.m_should_pay);
        stmt->setNumber(16,acct_item.m_favour_fee);
        stmt->setNumber(17,acct_item.m_times);
        stmt->setNumber(18,acct_item.m_duration);
        stmt->setNumber(19,acct_item.m_month_wrtoff_fee);
        stmt->setNumber(20,acct_item.m_pay_wrtoff_fee);
        stmt->setString(21,acct_item.m_attr_code);
    }
    else if (type == SELECT_BY_ACCT_ID)
    {
        stmt->setNumber(1,m_acct_id);
    }
    else if (type == UPDATE_STATE_AMOUNT)
    {
        stmt->setString(1,m_state);
        stmt->setNumber(2,m_amount);
        stmt->setNumber(3,m_acct_item_id);
    }
    else if (type == SELECT_BY_ACCT_ID_SERV_ID)
    {
        stmt->setNumber(1,m_acct_id);
        stmt->setNumber(2,m_serv_id);
        stmt->setNumber(3,m_acct_item_type_id);
        stmt->setString(4,m_state);
    }
    else if (type == UPDATE_OTHER_FEE)
    {
        stmt->setNumber(1,m_amount);
        stmt->setNumber(2,m_should_pay);
        stmt->setNumber(3,m_favour_fee);
        stmt->setNumber(4,m_acct_item_id);
    }
}

