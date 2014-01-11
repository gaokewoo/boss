#include "OweShortmsgCode.hh"

string OweShortmsgCode::insSQL="INSERT INTO OWE_SHORTMSG_CODE(REGION_CODE,SHORTMSG_CODE,SHORTMSG_NAME,SHORTMSG_LEVEL,SUBSECTION_NUM)VALUES (:REGION_CODE,:SHORTMSG_CODE,:SHORTMSG_NAME,:SHORTMSG_LEVEL,:SUBSECTION_NUM)";

void OweShortmsgCode::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweShortmsgCode::prepareSQL()
{
    stmt->setString(1,owe_shortmsg_code.m_region_code);
    stmt->setString(2,owe_shortmsg_code.m_shortmsg_code);
    stmt->setString(3,owe_shortmsg_code.m_shortmsg_name);
    stmt->setNumber(4,owe_shortmsg_code.m_shortmsg_level);
    stmt->setNumber(5,owe_shortmsg_code.m_subsection_num);
}

