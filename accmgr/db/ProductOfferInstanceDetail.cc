#include "ProductOfferInstanceDetail.hh"

string ProductOfferInstanceDetail::insSQL="INSERT INTO PRODUCT_OFFER_INSTANCE_DETAIL(INSTANCE_RELATION_ID,PRODUCT_OFFER_INSTANCE_ID,INSTANCE_TYPE,INSTANCE_ID,STATE,EFF_DATE,EXP_DATE,REL_GROUP_ID,REL_PROD_INST_ID,REL_OFFER_INST_ID,OFFER_MBR_ROLE_CD)VALUES (:INSTANCE_RELATION_ID,:PRODUCT_OFFER_INSTANCE_ID,:INSTANCE_TYPE,:INSTANCE_ID,:STATE,SYSDATE,SYSDATE,:REL_GROUP_ID,:REL_PROD_INST_ID,:REL_OFFER_INST_ID,:OFFER_MBR_ROLE_CD)";

void ProductOfferInstanceDetail::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ProductOfferInstanceDetail::prepareSQL()
{
    stmt->setNumber(1,product_offer_instance_detail.m_instance_relation_id);
    stmt->setNumber(2,product_offer_instance_detail.m_product_offer_instance_id);
    stmt->setString(3,product_offer_instance_detail.m_instance_type);
    stmt->setNumber(4,product_offer_instance_detail.m_instance_id);
    stmt->setString(5,product_offer_instance_detail.m_state);
    stmt->setNumber(6,product_offer_instance_detail.m_rel_group_id);
    stmt->setNumber(7,product_offer_instance_detail.m_rel_prod_inst_id);
    stmt->setNumber(8,product_offer_instance_detail.m_rel_offer_inst_id);
    stmt->setString(9,product_offer_instance_detail.m_offer_mbr_role_cd);
}

