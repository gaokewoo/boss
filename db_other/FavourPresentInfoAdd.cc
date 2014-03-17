#include "FavourPresentInfoAdd.hh"

string FavourPresentInfoAdd::insSQL="INSERT INTO FAVOUR_PRESENT_INFO_ADD(FAVOUR_PRESENT_ID,SERV_ID,PRESENT_RULE_ID,PRESENT_TYPE,PRIORITY,OP_CODE,PRESENT_ID,ACCT_ITEM_GROUP_ID,FAVOUR_FEE,PRESENT_RATE,EFF_DATE,EXP_DATE,STATE,STATE_DATE,OP_SN,OP_TYPE,OP_TIME)VALUES (:FAVOUR_PRESENT_ID,:SERV_ID,:PRESENT_RULE_ID,:PRESENT_TYPE,:PRIORITY,:OP_CODE,:PRESENT_ID,:ACCT_ITEM_GROUP_ID,:FAVOUR_FEE,:PRESENT_RATE,SYSDATE,SYSDATE,:STATE,SYSDATE,:OP_SN,:OP_TYPE,SYSDATE)";

void FavourPresentInfoAdd::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void FavourPresentInfoAdd::prepareSQL()
{
    stmt->setNumber(1,favour_present_info_add.m_favour_present_id);
    stmt->setNumber(2,favour_present_info_add.m_serv_id);
    stmt->setNumber(3,favour_present_info_add.m_present_rule_id);
    stmt->setString(4,favour_present_info_add.m_present_type);
    stmt->setNumber(5,favour_present_info_add.m_priority);
    stmt->setString(6,favour_present_info_add.m_op_code);
    stmt->setNumber(7,favour_present_info_add.m_present_id);
    stmt->setNumber(8,favour_present_info_add.m_acct_item_group_id);
    stmt->setNumber(9,favour_present_info_add.m_favour_fee);
    stmt->setNumber(10,favour_present_info_add.m_present_rate);
    stmt->setString(11,favour_present_info_add.m_state);
    stmt->setNumber(12,favour_present_info_add.m_op_sn);
    stmt->setString(13,favour_present_info_add.m_op_type);
}

