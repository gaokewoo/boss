#include "CustPostChg.hh"

string CustPostChg::insSQL="INSERT INTO CUST_POST_CHG(SEQ_NO,CONTRACT_NO,POST_FLAG,POST_TYPE,POST_ADDRESS,POST_ZIP,FAX_NO,MAIL_ADDRESS,ID_NO,POST_NAME,POSTNO_FLAG,CONTENT_TYPE,POST_CYC,OP_TYPE,DEAL_FLAG,DEAL_TIME)VALUES (:SEQ_NO,:CONTRACT_NO,:POST_FLAG,:POST_TYPE,:POST_ADDRESS,:POST_ZIP,:FAX_NO,:MAIL_ADDRESS,:ID_NO,:POST_NAME,:POSTNO_FLAG,:CONTENT_TYPE,:POST_CYC,:OP_TYPE,:DEAL_FLAG,SYSDATE)";

void CustPostChg::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CustPostChg::prepareSQL()
{
    stmt->setNumber(1,cust_post_chg.m_seq_no);
    stmt->setNumber(2,cust_post_chg.m_contract_no);
    stmt->setString(3,cust_post_chg.m_post_flag);
    stmt->setString(4,cust_post_chg.m_post_type);
    stmt->setString(5,cust_post_chg.m_post_address);
    stmt->setString(6,cust_post_chg.m_post_zip);
    stmt->setString(7,cust_post_chg.m_fax_no);
    stmt->setString(8,cust_post_chg.m_mail_address);
    stmt->setNumber(9,cust_post_chg.m_id_no);
    stmt->setString(10,cust_post_chg.m_post_name);
    stmt->setNumber(11,cust_post_chg.m_postno_flag);
    stmt->setString(12,cust_post_chg.m_content_type);
    stmt->setNumber(13,cust_post_chg.m_post_cyc);
    stmt->setString(14,cust_post_chg.m_op_type);
    stmt->setString(15,cust_post_chg.m_deal_flag);
}

