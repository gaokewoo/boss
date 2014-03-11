#include "ServProduct.hh"

string ServProduct::insSQL="INSERT INTO SERV_PRODUCT(SERV_PRODUCT_ID,SERV_ID,AGREEMENT_ID,PRODUCT_ID,CREATED_DATE,EFF_DATE,EXP_DATE,STATE,STOP_RENT_TIME,BEGIN_RENT_TIME)VALUES (:SERV_PRODUCT_ID,:SERV_ID,:AGREEMENT_ID,:PRODUCT_ID,SYSDATE,SYSDATE,SYSDATE,:STATE,SYSDATE,SYSDATE)";

void ServProduct::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServProduct::prepareSQL()
{
    stmt->setNumber(1,serv_product.m_serv_product_id);
    stmt->setNumber(2,serv_product.m_serv_id);
    stmt->setNumber(3,serv_product.m_agreement_id);
    stmt->setNumber(4,serv_product.m_product_id);
    stmt->setString(5,serv_product.m_state);
}

