#include "TariffRefType.hh"

string TariffRefType::insSQL="INSERT INTO TARIFF_REF_TYPE(TARIFF_ID,REF_VALUE_TYPE)VALUES (:TARIFF_ID,:REF_VALUE_TYPE)";

void TariffRefType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void TariffRefType::prepareSQL()
{
    stmt->setNumber(1,tariff_ref_type.m_tariff_id);
    stmt->setString(2,tariff_ref_type.m_ref_value_type);
}

