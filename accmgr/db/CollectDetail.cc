#include "CollectDetail.hh"

string CollectDetail::insSQL="INSERT INTO COLLECT_DETAIL(COLLECT_NBR,BILL_YM,ACCT_ID,SERV_ID,ACC_NBR,ACCT_ITEM_TYPE_ID,OWE_FEE,OWE_BEGIN_TIME,OWE_END_TIME)VALUES (:COLLECT_NBR,:BILL_YM,:ACCT_ID,:SERV_ID,:ACC_NBR,:ACCT_ITEM_TYPE_ID,:OWE_FEE,SYSDATE,SYSDATE)";

void CollectDetail::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CollectDetail::prepareSQL()
{
    stmt->setString(1,collect_detail.m_collect_nbr);
    stmt->setNumber(2,collect_detail.m_bill_ym);
    stmt->setNumber(3,collect_detail.m_acct_id);
    stmt->setNumber(4,collect_detail.m_serv_id);
    stmt->setString(5,collect_detail.m_acc_nbr);
    stmt->setNumber(6,collect_detail.m_acct_item_type_id);
    stmt->setNumber(7,collect_detail.m_owe_fee);
}

