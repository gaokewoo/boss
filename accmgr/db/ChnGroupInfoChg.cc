#include "ChnGroupInfoChg.hh"

string ChnGroupInfoChg::insSQL="INSERT INTO CHN_GROUP_INFO_CHG(SEQ_NO,GROUP_ID,PARENT_GROUP_ID,PARENT_LEVEL,CURRENT_LEVEL,BOSS_ORG_CODE,TOLL_NO,BEGIN_REGION,OP_TYPE,DEAL_FLAG,DEAL_TIME)VALUES (:SEQ_NO,:GROUP_ID,:PARENT_GROUP_ID,:PARENT_LEVEL,:CURRENT_LEVEL,:BOSS_ORG_CODE,:TOLL_NO,:BEGIN_REGION,:OP_TYPE,:DEAL_FLAG,SYSDATE)";

void ChnGroupInfoChg::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ChnGroupInfoChg::prepareSQL()
{
    stmt->setNumber(1,chn_group_info_chg.m_seq_no);
    stmt->setString(2,chn_group_info_chg.m_group_id);
    stmt->setString(3,chn_group_info_chg.m_parent_group_id);
    stmt->setNumber(4,chn_group_info_chg.m_parent_level);
    stmt->setNumber(5,chn_group_info_chg.m_current_level);
    stmt->setString(6,chn_group_info_chg.m_boss_org_code);
    stmt->setString(7,chn_group_info_chg.m_toll_no);
    stmt->setString(8,chn_group_info_chg.m_begin_region);
    stmt->setString(9,chn_group_info_chg.m_op_type);
    stmt->setString(10,chn_group_info_chg.m_deal_flag);
}

