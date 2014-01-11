#include "TariffCalcDesc.hh"

string TariffCalcDesc::insSQL="INSERT INTO TARIFF_CALC_DESC(TARIFF_CALC_ID,TARIFF_CALC_NAME)VALUES (:TARIFF_CALC_ID,:TARIFF_CALC_NAME)";

void TariffCalcDesc::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void TariffCalcDesc::prepareSQL()
{
    stmt->setNumber(1,tariff_calc_desc.m_tariff_calc_id);
    stmt->setString(2,tariff_calc_desc.m_tariff_calc_name);
}

