#include "Bank.hh"

string Bank::insSQL="INSERT INTO BANK(BANK_ID,BANK_NAME)VALUES (:BANK_ID,:BANK_NAME)";

void Bank::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Bank::prepareSQL()
{
    stmt->setNumber(1,bank.m_bank_id);
    stmt->setString(2,bank.m_bank_name);
}

