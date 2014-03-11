#include "ProductOfferDetail.hh"

string ProductOfferDetail::insSQL="INSERT INTO PRODUCT_OFFER_DETAIL(OFFER_ID,ELEMENT_TYPE,ELEMENT_ID,ELEMENT_CODE,OFFER_DETAIL_ROLE_CD,ELEMENT_DESC,OBJECT_AMOUNT_START,OBJECT_AMOUNT_END,ORDER_DEAL_FLAG,BILL_FLAG,MEM_PRIORITY,IS_PRICING_OBJ,STATE,CREATE_DATE,STATE_DATE,RULE_ID,SEL_FLAG)VALUES (:OFFER_ID,:ELEMENT_TYPE,:ELEMENT_ID,:ELEMENT_CODE,:OFFER_DETAIL_ROLE_CD,:ELEMENT_DESC,:OBJECT_AMOUNT_START,:OBJECT_AMOUNT_END,:ORDER_DEAL_FLAG,:BILL_FLAG,:MEM_PRIORITY,:IS_PRICING_OBJ,:STATE,SYSDATE,SYSDATE,:RULE_ID,:SEL_FLAG)";

void ProductOfferDetail::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ProductOfferDetail::prepareSQL()
{
    stmt->setNumber(1,product_offer_detail.m_offer_id);
    stmt->setString(2,product_offer_detail.m_element_type);
    stmt->setNumber(3,product_offer_detail.m_element_id);
    stmt->setNumber(4,product_offer_detail.m_element_code);
    stmt->setString(5,product_offer_detail.m_offer_detail_role_cd);
    stmt->setString(6,product_offer_detail.m_element_desc);
    stmt->setNumber(7,product_offer_detail.m_object_amount_start);
    stmt->setNumber(8,product_offer_detail.m_object_amount_end);
    stmt->setNumber(9,product_offer_detail.m_order_deal_flag);
    stmt->setNumber(10,product_offer_detail.m_bill_flag);
    stmt->setNumber(11,product_offer_detail.m_mem_priority);
    stmt->setString(12,product_offer_detail.m_is_pricing_obj);
    stmt->setString(13,product_offer_detail.m_state);
    stmt->setNumber(14,product_offer_detail.m_rule_id);
    stmt->setString(15,product_offer_detail.m_sel_flag);
}

