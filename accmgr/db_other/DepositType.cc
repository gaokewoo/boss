#include "DepositType.hh"

string DepositType::insSQL="INSERT INTO DEPOSIT_TYPE(DEPOSIT_TYPE,DEPOSIT_NAME,EXPIRE_TIME,VALID_MONTH,BAND_TYPE)VALUES (:DEPOSIT_TYPE,:DEPOSIT_NAME,SYSDATE,:VALID_MONTH,:BAND_TYPE)";

void DepositType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void DepositType::prepareSQL()
{
    stmt->setString(1,deposit_type.m_deposit_type);
    stmt->setString(2,deposit_type.m_deposit_name);
    stmt->setNumber(3,deposit_type.m_valid_month);
    stmt->setString(4,deposit_type.m_band_type);
}

