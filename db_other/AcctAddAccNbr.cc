#include "AcctAddAccNbr.hh"

string AcctAddAccNbr::insSQL="INSERT INTO ACCT_ADD_ACC_NBR(ACCT_ID,ADD_ACC_NBR_TYPE,ADD_ACC_NBR,STATE,STATE_DATE)VALUES (:ACCT_ID,:ADD_ACC_NBR_TYPE,:ADD_ACC_NBR,:STATE,SYSDATE)";

void AcctAddAccNbr::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctAddAccNbr::prepareSQL()
{
    stmt->setNumber(1,acct_add_acc_nbr.m_acct_id);
    stmt->setString(2,acct_add_acc_nbr.m_add_acc_nbr_type);
    stmt->setString(3,acct_add_acc_nbr.m_add_acc_nbr);
    stmt->setString(4,acct_add_acc_nbr.m_state);
}

