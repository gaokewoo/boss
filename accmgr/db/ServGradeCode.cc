#include "ServGradeCode.hh"

string ServGradeCode::insSQL="INSERT INTO SERV_GRADE_CODE(REGION_ID,OWNER_CODE,TYPE_NAME,VIP_FLAG,STOP_FLAG)VALUES (:REGION_ID,:OWNER_CODE,:TYPE_NAME,:VIP_FLAG,:STOP_FLAG)";

void ServGradeCode::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServGradeCode::prepareSQL()
{
    stmt->setNumber(1,serv_grade_code.m_region_id);
    stmt->setString(2,serv_grade_code.m_owner_code);
    stmt->setString(3,serv_grade_code.m_type_name);
    stmt->setString(4,serv_grade_code.m_vip_flag);
    stmt->setString(5,serv_grade_code.m_stop_flag);
}

