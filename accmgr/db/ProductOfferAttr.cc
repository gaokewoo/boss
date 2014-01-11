#include "ProductOfferAttr.hh"

string ProductOfferAttr::insSQL="INSERT INTO PRODUCT_OFFER_ATTR(OFFER_ATTR_SEQ,OFFER_ID,ATTR_VALUE_TYPE_ID,ATTR_VALUE_UNIT_ID,OFFER_ATTR_CHARACTER,OFFER_ATTR_VALUE,ALLOW_CUSTOMIZED_FLAG,EXCLUABLITY,IF_DEFAULT_VALUE,ELEMENT_TYPE,ELEMENT_ID,MIN_VALUE,MAX_VALUE,CREATE_DATE,STATE,STATE_DATE,ATTR_VALUE_RES,SHOWORDER)VALUES (:OFFER_ATTR_SEQ,:OFFER_ID,:ATTR_VALUE_TYPE_ID,:ATTR_VALUE_UNIT_ID,:OFFER_ATTR_CHARACTER,:OFFER_ATTR_VALUE,:ALLOW_CUSTOMIZED_FLAG,:EXCLUABLITY,:IF_DEFAULT_VALUE,:ELEMENT_TYPE,:ELEMENT_ID,:MIN_VALUE,:MAX_VALUE,SYSDATE,:STATE,SYSDATE,:ATTR_VALUE_RES,:SHOWORDER)";

void ProductOfferAttr::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ProductOfferAttr::prepareSQL()
{
    stmt->setNumber(1,product_offer_attr.m_offer_attr_seq);
    stmt->setNumber(2,product_offer_attr.m_offer_id);
    stmt->setNumber(3,product_offer_attr.m_attr_value_type_id);
    stmt->setNumber(4,product_offer_attr.m_attr_value_unit_id);
    stmt->setString(5,product_offer_attr.m_offer_attr_character);
    stmt->setString(6,product_offer_attr.m_offer_attr_value);
    stmt->setString(7,product_offer_attr.m_allow_customized_flag);
    stmt->setString(8,product_offer_attr.m_excluablity);
    stmt->setString(9,product_offer_attr.m_if_default_value);
    stmt->setString(10,product_offer_attr.m_element_type);
    stmt->setNumber(11,product_offer_attr.m_element_id);
    stmt->setNumber(12,product_offer_attr.m_min_value);
    stmt->setNumber(13,product_offer_attr.m_max_value);
    stmt->setString(14,product_offer_attr.m_state);
    stmt->setNumber(15,product_offer_attr.m_attr_value_res);
    stmt->setNumber(16,product_offer_attr.m_showorder);
}

