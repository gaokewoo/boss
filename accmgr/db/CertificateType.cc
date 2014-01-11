#include "CertificateType.hh"

string CertificateType::insSQL="INSERT INTO CERTIFICATE_TYPE(CERTIFICATE_TYPE,CERTIFICATE_TYPE_NAME,CERTIFICATE_LENGTH)VALUES (:CERTIFICATE_TYPE,:CERTIFICATE_TYPE_NAME,:CERTIFICATE_LENGTH)";

void CertificateType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CertificateType::prepareSQL()
{
    stmt->setString(1,certificate_type.m_certificate_type);
    stmt->setString(2,certificate_type.m_certificate_type_name);
    stmt->setNumber(3,certificate_type.m_certificate_length);
}

