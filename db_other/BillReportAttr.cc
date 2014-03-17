#include "BillReportAttr.hh"

string BillReportAttr::insSQL="INSERT INTO BILL_REPORT_ATTR(FUNCTION_NAME,DEST_TABLE,SRC_TABLE,ID_FLAG,BILLING_CYCLE_ID,OP_FLAG,CTR_FLAG,SRC_TABLE_SPACE,DEST_TABLE_SPACE,INDEX_SPACE,TABLE_OWNER,NOTE)VALUES (:FUNCTION_NAME,:DEST_TABLE,:SRC_TABLE,:ID_FLAG,:BILLING_CYCLE_ID,:OP_FLAG,:CTR_FLAG,:SRC_TABLE_SPACE,:DEST_TABLE_SPACE,:INDEX_SPACE,:TABLE_OWNER,:NOTE)";

void BillReportAttr::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillReportAttr::prepareSQL()
{
    stmt->setString(1,bill_report_attr.m_function_name);
    stmt->setString(2,bill_report_attr.m_dest_table);
    stmt->setString(3,bill_report_attr.m_src_table);
    stmt->setString(4,bill_report_attr.m_id_flag);
    stmt->setString(5,bill_report_attr.m_billing_cycle_id);
    stmt->setString(6,bill_report_attr.m_op_flag);
    stmt->setNumber(7,bill_report_attr.m_ctr_flag);
    stmt->setString(8,bill_report_attr.m_src_table_space);
    stmt->setString(9,bill_report_attr.m_dest_table_space);
    stmt->setString(10,bill_report_attr.m_index_space);
    stmt->setString(11,bill_report_attr.m_table_owner);
    stmt->setString(12,bill_report_attr.m_note);
}

