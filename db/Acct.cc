#include "Acct.hh"

string Acct::insSQL="INSERT INTO ACCT(ACCT_ID,CUST_ID,ACCT_NAME,ADDRESS_ID,STATE,STATE_DATE,ACCT_PWD,REGION_ID,ACCT_TYPE,OWE_MIN_YM,OWE_FEE)VALUES (:ACCT_ID,:CUST_ID,:ACCT_NAME,:ADDRESS_ID,:STATE,SYSDATE,:ACCT_PWD,:REGION_ID,:ACCT_TYPE,:OWE_MIN_YM,:OWE_FEE)";

void Acct::insertData()
{
    type = INSERT;
    setSQL(insSQL);
    executeUpdate();
}

ST_ACCT Acct::getAcctByAcctId(long acct_id)
{
    type=SELECT_BY_ACCT_ID;
    m_acct_id=acct_id;
    setSQL("SELECT ACCT_ID,CUST_ID,ACCT_NAME,ADDRESS_ID,STATE,TO_CHAR(STATE_DATE,'YYYYMMDDHH24MISS'),ACCT_PWD,REGION_ID,ACCT_TYPE,OWE_MIN_YM,OWE_FEE FROM ACCT WHERE ACCT_ID=:ACCT_ID");
    executeQuery();

    return acct;
}

void Acct::setAcctOweMinYMAndOweFee(long acct_id,long owe_min_ym,long owe_fee)
{
    type=UPDATE_YM;
    m_acct_id=acct_id;
    m_owe_min_ym=owe_min_ym;
    m_owe_fee=owe_fee;

    setSQL("UPDATE ACCT SET OWE_MIN_YM=:OWE_MIN_YM,OWE_FEE=:OWE_FEE WHERE ACCT_ID=:ACCT_ID");

    executeUpdate();
}

void Acct::prepareSQL()
{
    if (type == INSERT)
    {
        stmt->setNumber(1,acct.m_acct_id);
        stmt->setNumber(2,acct.m_cust_id);
        stmt->setString(3,acct.m_acct_name);
        stmt->setNumber(4,acct.m_address_id);
        stmt->setString(5,acct.m_state);
        stmt->setString(6,acct.m_acct_pwd);
        stmt->setNumber(7,acct.m_region_id);
        stmt->setString(8,acct.m_acct_type);
        stmt->setNumber(9,acct.m_owe_min_ym);
        stmt->setNumber(10,acct.m_owe_fee);
    }
    else if(type == SELECT_BY_ACCT_ID)
    {
        stmt->setNumber(1,m_acct_id);
    }
    else if(type == UPDATE_YM)
    {
        stmt->setNumber(1,m_owe_min_ym);
        stmt->setNumber(2,m_owe_fee);
        stmt->setNumber(3,m_acct_id);
    }
}

void Acct::doParse()
{
    acct.m_acct_id = (long)rset->getNumber(1);
    acct.m_cust_id = (long)rset->getNumber(2);
    acct.m_acct_name = rset->getString(3);
    acct.m_address_id = (long)rset->getNumber(4);
    acct.m_state = rset->getString(5);
    acct.m_state_date = rset->getString(6);
    acct.m_acct_pwd = rset->getString(7);
    acct.m_region_id = (long)rset->getNumber(8);
    acct.m_acct_type = rset->getString(9);
    acct.m_owe_min_ym = (long)rset->getNumber(10);
    acct.m_owe_fee = (long)rset->getNumber(11);
}

