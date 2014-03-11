#include "OweShortmsgContent.hh"

string OweShortmsgContent::insSQL="INSERT INTO OWE_SHORTMSG_CONTENT(REGION_CODE,SHORTMSG_CODE,SERIAL_NO,PARAMETER_NO,SHORTMSG_CONTENT)VALUES (:REGION_CODE,:SHORTMSG_CODE,:SERIAL_NO,:PARAMETER_NO,:SHORTMSG_CONTENT)";

void OweShortmsgContent::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweShortmsgContent::prepareSQL()
{
    stmt->setString(1,owe_shortmsg_content.m_region_code);
    stmt->setString(2,owe_shortmsg_content.m_shortmsg_code);
    stmt->setNumber(3,owe_shortmsg_content.m_serial_no);
    stmt->setNumber(4,owe_shortmsg_content.m_parameter_no);
    stmt->setString(5,owe_shortmsg_content.m_shortmsg_content);
}

