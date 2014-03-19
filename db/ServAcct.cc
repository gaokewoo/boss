#include "ServAcct.hh"

string ServAcct::insSQL="INSERT INTO SERV_ACCT(SERV_ACCT_ID,ACCT_ID,SERV_ID,BILLING_CYCLE_TYPE_ID,ACCT_ITEM_GROUP_ID,PRIORITY,PAYMENT_RULE_ID,PAYMENT_LIMIT_TYPE,PAYMENT_LIMIT,STATE,STATE_DATE,PAY_PRIORITY,EFF_DATE,EXP_DATE)VALUES (:SERV_ACCT_ID,:ACCT_ID,:SERV_ID,:BILLING_CYCLE_TYPE_ID,:ACCT_ITEM_GROUP_ID,:PRIORITY,:PAYMENT_RULE_ID,:PAYMENT_LIMIT_TYPE,:PAYMENT_LIMIT,:STATE,SYSDATE,:PAY_PRIORITY,SYSDATE,SYSDATE+3650)";

void ServAcct::insertData()
{
    op_type=INSERT;
    setSQL(insSQL);
    executeUpdate();
}

void ServAcct::prepareSQL()
{
    if(op_type == INSERT)
    {
        stmt->setNumber(1,serv_acct.m_serv_acct_id);
        stmt->setNumber(2,serv_acct.m_acct_id);
        stmt->setNumber(3,serv_acct.m_serv_id);
        stmt->setNumber(4,serv_acct.m_billing_cycle_type_id);
        stmt->setNumber(5,serv_acct.m_acct_item_group_id);
        stmt->setNumber(6,serv_acct.m_priority);
        stmt->setNumber(7,serv_acct.m_payment_rule_id);
        stmt->setString(8,serv_acct.m_payment_limit_type);
        stmt->setNumber(9,serv_acct.m_payment_limit);
        stmt->setString(10,serv_acct.m_state);
        stmt->setNumber(11,serv_acct.m_pay_priority);
    }
    else if(op_type == SELECT_BY_SERV_ID)
    {
        stmt->setNumber(1,m_serv_id);
    }
}

ST_SERV_ACCT ServAcct::getServAcctByServId(long serv_id)
{
    op_type=SELECT_BY_SERV_ID;
    m_serv_id = serv_id;
    setSQL("SELECT SERV_ACCT_ID,ACCT_ID,SERV_ID,BILLING_CYCLE_TYPE_ID,ACCT_ITEM_GROUP_ID,PRIORITY,PAYMENT_RULE_ID,PAYMENT_LIMIT_TYPE,PAYMENT_LIMIT,STATE,TO_CHAR(STATE_DATE,'YYYYMMDDHH24MISS'),PAY_PRIORITY,TO_CHAR(EFF_DATE,'YYYYMMDDHH24MISS'),TO_CHAR(EXP_DATE,'YYYYMMDDHH24MISS') FROM SERV_ACCT WHERE SERV_ID=:SERV_ID");
    executeQuery();

    if(v_data.empty())
    {
        cerr<<"No related data with serv_id:"<<serv_id<<endl;

        throw;
    }

    return v_data[0];
}

void ServAcct::doParse()
{
    serv_acct.m_serv_acct_id = (long)rset->getNumber(1);
    serv_acct.m_acct_id = (long)rset->getNumber(2);
    serv_acct.m_serv_id = (long)rset->getNumber(3);
    serv_acct.m_billing_cycle_type_id = (long)rset->getNumber(4);
    serv_acct.m_acct_item_group_id = (long)rset->getNumber(5);
    serv_acct.m_priority = (long)rset->getNumber(6);
    serv_acct.m_payment_rule_id = (long)rset->getNumber(7);
    serv_acct.m_payment_limit_type = rset->getString(8);
    serv_acct.m_payment_limit = (long)rset->getNumber(9);
    serv_acct.m_state = rset->getString(10);
    serv_acct.m_state_date = rset->getString(11);
    serv_acct.m_pay_priority = (long)rset->getNumber(12);
    serv_acct.m_eff_date = rset->getString(13);
    serv_acct.m_exp_date = rset->getString(14);

    v_data.push_back(serv_acct);
}

