#include "BillUnownerChg.hh"

string BillUnownerChg::insSQL="INSERT INTO BILL_UNOWNER_CHG(BILL_UNOWNER_ID,ACC_NBR,UNOWNER_TYPE,REGION_CODE,IMSI_NO,UNOWNER_FEE,UNOWNER_COUNT,UNOWNER_BEGIN_TIME,UNOWNER_LAST_TIME,INSERT_TIME,STATE,STATE_DATE,OP_TYPE,DEAL_FLAG)VALUES (:BILL_UNOWNER_ID,:ACC_NBR,:UNOWNER_TYPE,:REGION_CODE,:IMSI_NO,:UNOWNER_FEE,:UNOWNER_COUNT,SYSDATE,SYSDATE,SYSDATE,:STATE,SYSDATE,:OP_TYPE,:DEAL_FLAG)";

void BillUnownerChg::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillUnownerChg::prepareSQL()
{
    stmt->setNumber(1,bill_unowner_chg.m_bill_unowner_id);
    stmt->setString(2,bill_unowner_chg.m_acc_nbr);
    stmt->setString(3,bill_unowner_chg.m_unowner_type);
    stmt->setString(4,bill_unowner_chg.m_region_code);
    stmt->setString(5,bill_unowner_chg.m_imsi_no);
    stmt->setNumber(6,bill_unowner_chg.m_unowner_fee);
    stmt->setNumber(7,bill_unowner_chg.m_unowner_count);
    stmt->setString(8,bill_unowner_chg.m_state);
    stmt->setString(9,bill_unowner_chg.m_op_type);
    stmt->setString(10,bill_unowner_chg.m_deal_flag);
}

