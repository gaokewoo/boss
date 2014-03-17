#include "TariffUnit.hh"

string TariffUnit::insSQL="INSERT INTO TARIFF_UNIT(TARIFF_UNIT_ID,MEASURE_METHOD_ID,TARIFF_UNIT_NAME,STANDARD_CONVERSION_RATE)VALUES (:TARIFF_UNIT_ID,:MEASURE_METHOD_ID,:TARIFF_UNIT_NAME,:STANDARD_CONVERSION_RATE)";

void TariffUnit::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void TariffUnit::prepareSQL()
{
    stmt->setNumber(1,tariff_unit.m_tariff_unit_id);
    stmt->setNumber(2,tariff_unit.m_measure_method_id);
    stmt->setString(3,tariff_unit.m_tariff_unit_name);
    stmt->setNumber(4,tariff_unit.m_standard_conversion_rate);
}

