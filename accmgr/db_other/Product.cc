#include "Product.hh"

string Product::insSQL="INSERT INTO PRODUCT(PRODUCT_ID,PRODUCT_PROVIDER_ID,PRICING_PLAN_ID,PRODUCT_FAMILY_ID,PRODUCT_NAME,PRODUCT_COMMENTS,PRODUCT_TYPE,PRODUCT_CLASSIFICATION,PRODUCT_CODE,STATE,EFF_DATE,EXP_DATE)VALUES (:PRODUCT_ID,:PRODUCT_PROVIDER_ID,:PRICING_PLAN_ID,:PRODUCT_FAMILY_ID,:PRODUCT_NAME,:PRODUCT_COMMENTS,:PRODUCT_TYPE,:PRODUCT_CLASSIFICATION,:PRODUCT_CODE,:STATE,SYSDATE,SYSDATE)";

void Product::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Product::prepareSQL()
{
    stmt->setNumber(1,product.m_product_id);
    stmt->setNumber(2,product.m_product_provider_id);
    stmt->setNumber(3,product.m_pricing_plan_id);
    stmt->setNumber(4,product.m_product_family_id);
    stmt->setString(5,product.m_product_name);
    stmt->setString(6,product.m_product_comments);
    stmt->setString(7,product.m_product_type);
    stmt->setString(8,product.m_product_classification);
    stmt->setString(9,product.m_product_code);
    stmt->setString(10,product.m_state);
}

