#include "BillParse.hh"

string BillParse::insSQL="INSERT INTO BILL_PARSE(BILL_PARSE_ID,PARSE_SN,ATTR_GRP_ID,PARSE_METHOD,FEE_METHOD,ACCT_ITEM_TYPE_ID,SP_ITEM_ID)VALUES (:BILL_PARSE_ID,:PARSE_SN,:ATTR_GRP_ID,:PARSE_METHOD,:FEE_METHOD,:ACCT_ITEM_TYPE_ID,:SP_ITEM_ID)";

void BillParse::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillParse::prepareSQL()
{
    stmt->setNumber(1,bill_parse.m_bill_parse_id);
    stmt->setNumber(2,bill_parse.m_parse_sn);
    stmt->setNumber(3,bill_parse.m_attr_grp_id);
    stmt->setString(4,bill_parse.m_parse_method);
    stmt->setString(5,bill_parse.m_fee_method);
    stmt->setNumber(6,bill_parse.m_acct_item_type_id);
    stmt->setNumber(7,bill_parse.m_sp_item_id);
}

