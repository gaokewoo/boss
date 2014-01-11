#include "AcctAddAccNbrDead.hh"

string AcctAddAccNbrDead::insSQL="INSERT INTO ACCT_ADD_ACC_NBR_DEAD(ACCT_ID,ADD_ACC_NBR_TYPE,ADD_ACC_NBR,STATE,STATE_DATE,DEAD_TIME,DEAD_STAFF_ID,DEAD_OPTSN)VALUES (:ACCT_ID,:ADD_ACC_NBR_TYPE,:ADD_ACC_NBR,:STATE,SYSDATE,SYSDATE,:DEAD_STAFF_ID,:DEAD_OPTSN)";

void AcctAddAccNbrDead::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctAddAccNbrDead::prepareSQL()
{
    stmt->setNumber(1,acct_add_acc_nbr_dead.m_acct_id);
    stmt->setString(2,acct_add_acc_nbr_dead.m_add_acc_nbr_type);
    stmt->setString(3,acct_add_acc_nbr_dead.m_add_acc_nbr);
    stmt->setString(4,acct_add_acc_nbr_dead.m_state);
    stmt->setNumber(5,acct_add_acc_nbr_dead.m_dead_staff_id);
    stmt->setNumber(6,acct_add_acc_nbr_dead.m_dead_optsn);
}

