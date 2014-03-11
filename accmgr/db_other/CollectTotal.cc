#include "CollectTotal.hh"

string CollectTotal::insSQL="INSERT INTO COLLECT_TOTAL(COLLECT_NBR,BILL_YM,COLLECT_OP_MARK,COLLECT_MONEY,REFUSE_COUNT,COLLECT_COUNT,REFUSE_MONEY)VALUES (:COLLECT_NBR,:BILL_YM,:COLLECT_OP_MARK,:COLLECT_MONEY,:REFUSE_COUNT,:COLLECT_COUNT,:REFUSE_MONEY)";

void CollectTotal::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CollectTotal::prepareSQL()
{
    stmt->setString(1,collect_total.m_collect_nbr);
    stmt->setNumber(2,collect_total.m_bill_ym);
    stmt->setString(3,collect_total.m_collect_op_mark);
    stmt->setNumber(4,collect_total.m_collect_money);
    stmt->setNumber(5,collect_total.m_refuse_count);
    stmt->setNumber(6,collect_total.m_collect_count);
    stmt->setNumber(7,collect_total.m_refuse_money);
}

