#include "CertificateType.hh"

string CertificateType::insSQL="INSERT INTO CERTIFICATE_TYPE(CERTIFICATE_TYPE,CERTIFICATE_TYPE_NAME,CERTIFICATE_LENGTH)VALUES (:CERTIFICATE_TYPE,:CERTIFICATE_TYPE_NAME,:CERTIFICATE_LENGTH)";

string CertificateType::emptySQL="DELETE FROM CERTIFICATE_TYPE";

string CertificateType::selectAllSQL="SELECT CERTIFICATE_TYPE,CERTIFICATE_TYPE_NAME,CERTIFICATE_LENGTH FROM CERTIFICATE_TYPE";

void CertificateType::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void CertificateType::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_CERTIFICATE_TYPE> CertificateType::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void CertificateType::doParse()
{
    certificate_type.m_certificate_type = rset->getString(1);
    certificate_type.m_certificate_type_name = rset->getString(2);
    certificate_type.m_certificate_length = (long)rset->getNumber(3);

    v_data.push_back(certificate_type);
}

void CertificateType::prepareSQL()
{
    if (type == 0)
    {
    stmt->setString(1,certificate_type.m_certificate_type);
    stmt->setString(2,certificate_type.m_certificate_type_name);
    stmt->setNumber(3,certificate_type.m_certificate_length);
    }
}

