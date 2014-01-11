#include "Operator.hh"

string Operator::insSQL="INSERT INTO OPERATOR(OPERATOR_ID,OPERATOR_NAME)VALUES (:OPERATOR_ID,:OPERATOR_NAME)";

void Operator::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Operator::prepareSQL()
{
    stmt->setNumber(1,oper.m_operator_id);
    stmt->setString(2,oper.m_operator_name);
}

