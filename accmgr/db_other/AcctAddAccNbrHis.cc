#include "AcctAddAccNbrHis.hh"

string AcctAddAccNbrHis::insSQL="INSERT INTO ACCT_ADD_ACC_NBR_HIS(ACCT_ID,ADD_ACC_NBR_TYPE,ADD_ACC_NBR,STATE,STATE_DATE,HIS_DATE,HIS_STAFF_ID,HIS_OPTSN)VALUES (:ACCT_ID,:ADD_ACC_NBR_TYPE,:ADD_ACC_NBR,:STATE,SYSDATE,SYSDATE,:HIS_STAFF_ID,:HIS_OPTSN)";

void AcctAddAccNbrHis::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctAddAccNbrHis::prepareSQL()
{
    stmt->setNumber(1,acct_add_acc_nbr_his.m_acct_id);
    stmt->setString(2,acct_add_acc_nbr_his.m_add_acc_nbr_type);
    stmt->setString(3,acct_add_acc_nbr_his.m_add_acc_nbr);
    stmt->setString(4,acct_add_acc_nbr_his.m_state);
    stmt->setNumber(5,acct_add_acc_nbr_his.m_his_staff_id);
    stmt->setNumber(6,acct_add_acc_nbr_his.m_his_optsn);
}

