#include "ChnGroupMsgChg.hh"

string ChnGroupMsgChg::insSQL="INSERT INTO CHN_GROUP_MSG_CHG(SEQ_NO,GROUP_ID,BOSS_ORG_CODE,GROUP_NAME,ROOT_DISTANCE,CLASS_CODE,IS_ACTIVE,ACTIVE_TIME,OP_TYPE,DEAL_FLAG,DEAL_TIME)VALUES (:SEQ_NO,:GROUP_ID,:BOSS_ORG_CODE,:GROUP_NAME,:ROOT_DISTANCE,:CLASS_CODE,:IS_ACTIVE,SYSDATE,:OP_TYPE,:DEAL_FLAG,SYSDATE)";

void ChnGroupMsgChg::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ChnGroupMsgChg::prepareSQL()
{
    stmt->setNumber(1,chn_group_msg_chg.m_seq_no);
    stmt->setString(2,chn_group_msg_chg.m_group_id);
    stmt->setString(3,chn_group_msg_chg.m_boss_org_code);
    stmt->setString(4,chn_group_msg_chg.m_group_name);
    stmt->setNumber(5,chn_group_msg_chg.m_root_distance);
    stmt->setString(6,chn_group_msg_chg.m_class_code);
    stmt->setString(7,chn_group_msg_chg.m_is_active);
    stmt->setString(8,chn_group_msg_chg.m_op_type);
    stmt->setString(9,chn_group_msg_chg.m_deal_flag);
}

