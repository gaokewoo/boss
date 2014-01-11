#include "StopServOweBc.hh"

string StopServOweBc::insSQL="INSERT INTO STOP_SERV_OWE_BC(SERV_ID,ACTION_TYPE_ID,NEW_STATUS,STAFF_CODE,OLD_STATUS,ACC_NBR,BILLING_MODE,PRODUCT_ID)VALUES (:SERV_ID,:ACTION_TYPE_ID,:NEW_STATUS,:STAFF_CODE,:OLD_STATUS,:ACC_NBR,:BILLING_MODE,:PRODUCT_ID)";

void StopServOweBc::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void StopServOweBc::prepareSQL()
{
    stmt->setNumber(1,stop_serv_owe_bc.m_serv_id);
    stmt->setNumber(2,stop_serv_owe_bc.m_action_type_id);
    stmt->setString(3,stop_serv_owe_bc.m_new_status);
    stmt->setString(4,stop_serv_owe_bc.m_staff_code);
    stmt->setString(5,stop_serv_owe_bc.m_old_status);
    stmt->setString(6,stop_serv_owe_bc.m_acc_nbr);
    stmt->setString(7,stop_serv_owe_bc.m_billing_mode);
    stmt->setNumber(8,stop_serv_owe_bc.m_product_id);
}

