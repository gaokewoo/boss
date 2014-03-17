#include "FavourPresentDetail.hh"

string FavourPresentDetail::insSQL="INSERT INTO FAVOUR_PRESENT_DETAIL(FAVOUR_PRESENT_ID,RATABLE_CYCLE_ID,OLD_FAVOUR_FEE,CURR_FAVOUR_FEE,DEAL_DATE)VALUES (:FAVOUR_PRESENT_ID,:RATABLE_CYCLE_ID,:OLD_FAVOUR_FEE,:CURR_FAVOUR_FEE,SYSDATE)";

void FavourPresentDetail::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void FavourPresentDetail::prepareSQL()
{
    stmt->setNumber(1,favour_present_detail.m_favour_present_id);
    stmt->setNumber(2,favour_present_detail.m_ratable_cycle_id);
    stmt->setNumber(3,favour_present_detail.m_old_favour_fee);
    stmt->setNumber(4,favour_present_detail.m_curr_favour_fee);
}

