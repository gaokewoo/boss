#include "StopServState.hh"

string StopServState::insSQL="INSERT INTO STOP_SERV_STATE(SERV_ID,CUST_ID,PRODUCT_ID,STATE,STATE_DATE,ACC_NBR,GROUP_ID,EFF_DATE,EXP_DATE,BILLING_MODE)VALUES (:SERV_ID,:CUST_ID,:PRODUCT_ID,:STATE,SYSDATE,:ACC_NBR,:GROUP_ID,SYSDATE,SYSDATE,:BILLING_MODE)";

void StopServState::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void StopServState::prepareSQL()
{
    stmt->setNumber(1,stop_serv_state.m_serv_id);
    stmt->setNumber(2,stop_serv_state.m_cust_id);
    stmt->setNumber(3,stop_serv_state.m_product_id);
    stmt->setString(4,stop_serv_state.m_state);
    stmt->setString(5,stop_serv_state.m_acc_nbr);
    stmt->setString(6,stop_serv_state.m_group_id);
    stmt->setString(7,stop_serv_state.m_billing_mode);
}

