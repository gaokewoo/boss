#include "UserAttrChg.hh"

string UserAttrChg::insSQL="INSERT INTO USER_ATTR_CHG(ID_NO,ATTR_CODE,LIMIT_OWE,DEAL_FLAG,DEAL_TIME)VALUES (:ID_NO,:ATTR_CODE,:LIMIT_OWE,:DEAL_FLAG,SYSDATE)";

void UserAttrChg::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void UserAttrChg::prepareSQL()
{
    stmt->setNumber(1,user_attr_chg.m_id_no);
    stmt->setString(2,user_attr_chg.m_attr_code);
    stmt->setNumber(3,user_attr_chg.m_limit_owe);
    stmt->setString(4,user_attr_chg.m_deal_flag);
}

