#include "CustContactInfo.hh"

string CustContactInfo::insSQL="INSERT INTO CUST_CONTACT_INFO(CUST_ID,AGREEMENT_ID,CONTACT_NAME,CONTACT_GENDER,CONTACT_ADDR,CONTACT_COMPANY,DUTY_DESC,TELEPHONE,MOBILE,POST_CODE,EMAIL_ADDRESS,FAX,COMMENTS,EFF_DATE,EXP_DATE)VALUES (:CUST_ID,:AGREEMENT_ID,:CONTACT_NAME,:CONTACT_GENDER,:CONTACT_ADDR,:CONTACT_COMPANY,:DUTY_DESC,:TELEPHONE,:MOBILE,:POST_CODE,:EMAIL_ADDRESS,:FAX,:COMMENTS,SYSDATE,SYSDATE)";

void CustContactInfo::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CustContactInfo::prepareSQL()
{
    stmt->setNumber(1,cust_contact_info.m_cust_id);
    stmt->setNumber(2,cust_contact_info.m_agreement_id);
    stmt->setString(3,cust_contact_info.m_contact_name);
    stmt->setString(4,cust_contact_info.m_contact_gender);
    stmt->setString(5,cust_contact_info.m_contact_addr);
    stmt->setString(6,cust_contact_info.m_contact_company);
    stmt->setString(7,cust_contact_info.m_duty_desc);
    stmt->setString(8,cust_contact_info.m_telephone);
    stmt->setString(9,cust_contact_info.m_mobile);
    stmt->setString(10,cust_contact_info.m_post_code);
    stmt->setString(11,cust_contact_info.m_email_address);
    stmt->setString(12,cust_contact_info.m_fax);
    stmt->setString(13,cust_contact_info.m_comments);
}

