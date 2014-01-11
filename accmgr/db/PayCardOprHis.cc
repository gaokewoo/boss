#include "PayCardOprHis.hh"

string PayCardOprHis::insSQL="INSERT INTO PAY_CARD_OPR_HIS(PAYMENT_ID,CARD_TYPE,CARD_NBR,CARD_FEE,HIS_DATE)VALUES (:PAYMENT_ID,:CARD_TYPE,:CARD_NBR,:CARD_FEE,SYSDATE)";

void PayCardOprHis::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PayCardOprHis::prepareSQL()
{
    stmt->setNumber(1,pay_card_opr_his.m_payment_id);
    stmt->setString(2,pay_card_opr_his.m_card_type);
    stmt->setString(3,pay_card_opr_his.m_card_nbr);
    stmt->setNumber(4,pay_card_opr_his.m_card_fee);
}

