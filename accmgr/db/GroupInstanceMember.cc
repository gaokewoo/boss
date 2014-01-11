#include "GroupInstanceMember.hh"

string GroupInstanceMember::insSQL="INSERT INTO GROUP_INSTANCE_MEMBER(MEMBER_ID,GROUP_ID,ACC_NBR,SHORT_NUM,SERV_ID,MEMBER_DESC,MEMBER_TYPE_ID,MEMBER_ROLE_ID,LIFE_CYCLE_ID,MEMBER_OBJECT_ID,STATE,STATE_DATE,EXP_DATE,EFF_DATE,GRP_MEB_ATTR,UP_GROUP_ID)VALUES (:MEMBER_ID,:GROUP_ID,:ACC_NBR,:SHORT_NUM,:SERV_ID,:MEMBER_DESC,:MEMBER_TYPE_ID,:MEMBER_ROLE_ID,:LIFE_CYCLE_ID,:MEMBER_OBJECT_ID,:STATE,SYSDATE,SYSDATE,SYSDATE,:GRP_MEB_ATTR,:UP_GROUP_ID)";

void GroupInstanceMember::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void GroupInstanceMember::prepareSQL()
{
    stmt->setNumber(1,group_instance_member.m_member_id);
    stmt->setNumber(2,group_instance_member.m_group_id);
    stmt->setString(3,group_instance_member.m_acc_nbr);
    stmt->setString(4,group_instance_member.m_short_num);
    stmt->setNumber(5,group_instance_member.m_serv_id);
    stmt->setString(6,group_instance_member.m_member_desc);
    stmt->setNumber(7,group_instance_member.m_member_type_id);
    stmt->setNumber(8,group_instance_member.m_member_role_id);
    stmt->setNumber(9,group_instance_member.m_life_cycle_id);
    stmt->setNumber(10,group_instance_member.m_member_object_id);
    stmt->setString(11,group_instance_member.m_state);
    stmt->setString(12,group_instance_member.m_grp_meb_attr);
    stmt->setNumber(13,group_instance_member.m_up_group_id);
}

