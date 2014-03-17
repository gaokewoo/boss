#include "Band.hh"

string Band::insSQL="INSERT INTO BAND(BAND_ID,BAN_BAND_ID,BAND_TYPE,BAND_NAME,BAND_DESC,IDEA,SLOGAN,CREATED_DAT,SM_CODE)VALUES (:BAND_ID,:BAN_BAND_ID,:BAND_TYPE,:BAND_NAME,:BAND_DESC,:IDEA,:SLOGAN,SYSDATE,:SM_CODE)";

void Band::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Band::prepareSQL()
{
    stmt->setNumber(1,band.m_band_id);
    stmt->setNumber(2,band.m_ban_band_id);
    stmt->setString(3,band.m_band_type);
    stmt->setString(4,band.m_band_name);
    stmt->setString(5,band.m_band_desc);
    stmt->setString(6,band.m_idea);
    stmt->setString(7,band.m_slogan);
    stmt->setString(8,band.m_sm_code);
}

