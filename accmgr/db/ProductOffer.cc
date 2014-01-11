#include "ProductOffer.hh"

string ProductOffer::insSQL="INSERT INTO PRODUCT_OFFER(OFFER_ID,BAND_ID,PRICING_PLAN_ID,OFFER_ATTR_TYPE,OFFER_NAME,OFFER_COMMENTS,CAN_BE_BUY_ALONE,OFFER_CODE,PRIORITY,STATE,EFF_DATE,EXP_DATE,BEGIN_DATE,END_DATE,REDOFLAG,MIN_NUM,MAX_NUM,EXP_DATE_OFFSET,EXP_DATE_OFFSET_UNIT,USER_RANGE,OFFER_TYPE,STATE_CHG_DATE,OFFER_CRT_DATE,GROUP_TYPE_ID,GROUP_LIMIT_RULE,PROD_OFFER_PUBLISHER,CUSTOM_REQUEST,OPERATION_MODLE,EFF_TYPE,EXP_TYPE,MIN_ORDER_NUM,MAX_ORDER_NUM,IF_CUST_PRICE)VALUES (:OFFER_ID,:BAND_ID,:PRICING_PLAN_ID,:OFFER_ATTR_TYPE,:OFFER_NAME,:OFFER_COMMENTS,:CAN_BE_BUY_ALONE,:OFFER_CODE,:PRIORITY,:STATE,SYSDATE,SYSDATE,SYSDATE,SYSDATE,:REDOFLAG,:MIN_NUM,:MAX_NUM,:EXP_DATE_OFFSET,:EXP_DATE_OFFSET_UNIT,:USER_RANGE,:OFFER_TYPE,SYSDATE,SYSDATE,:GROUP_TYPE_ID,:GROUP_LIMIT_RULE,:PROD_OFFER_PUBLISHER,:CUSTOM_REQUEST,:OPERATION_MODLE,:EFF_TYPE,:EXP_TYPE,:MIN_ORDER_NUM,:MAX_ORDER_NUM,:IF_CUST_PRICE)";

void ProductOffer::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ProductOffer::prepareSQL()
{
    stmt->setNumber(1,product_offer.m_offer_id);
    stmt->setNumber(2,product_offer.m_band_id);
    stmt->setNumber(3,product_offer.m_pricing_plan_id);
    stmt->setString(4,product_offer.m_offer_attr_type);
    stmt->setString(5,product_offer.m_offer_name);
    stmt->setString(6,product_offer.m_offer_comments);
    stmt->setString(7,product_offer.m_can_be_buy_alone);
    stmt->setString(8,product_offer.m_offer_code);
    stmt->setNumber(9,product_offer.m_priority);
    stmt->setString(10,product_offer.m_state);
    stmt->setString(11,product_offer.m_redoflag);
    stmt->setNumber(12,product_offer.m_min_num);
    stmt->setNumber(13,product_offer.m_max_num);
    stmt->setNumber(14,product_offer.m_exp_date_offset);
    stmt->setNumber(15,product_offer.m_exp_date_offset_unit);
    stmt->setString(16,product_offer.m_user_range);
    stmt->setNumber(17,product_offer.m_offer_type);
    stmt->setNumber(18,product_offer.m_group_type_id);
    stmt->setNumber(19,product_offer.m_group_limit_rule);
    stmt->setString(20,product_offer.m_prod_offer_publisher);
    stmt->setString(21,product_offer.m_custom_request);
    stmt->setString(22,product_offer.m_operation_modle);
    stmt->setString(23,product_offer.m_eff_type);
    stmt->setString(24,product_offer.m_exp_type);
    stmt->setNumber(25,product_offer.m_min_order_num);
    stmt->setNumber(26,product_offer.m_max_order_num);
    stmt->setString(27,product_offer.m_if_cust_price);
}

