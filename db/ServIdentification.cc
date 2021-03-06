#include "ServIdentification.hh"

string ServIdentification::insSQL="INSERT INTO SERV_IDENTIFICATION(SERV_ID,AGREEMENT_ID,ACC_NBR,EFF_DATE,EXP_DATE)VALUES (:SERV_ID,:AGREEMENT_ID,:ACC_NBR,SYSDATE,SYSDATE+365)";

void ServIdentification::insertData()
{
    op_type=INS;
    setSQL(insSQL);
    executeUpdate();
}

void ServIdentification::prepareSQL()
{
    if(op_type == INS)
    {
        stmt->setNumber(1,serv_identification.m_serv_id);
        stmt->setNumber(2,serv_identification.m_agreement_id);
        stmt->setString(3,serv_identification.m_acc_nbr);
    }
    else if(op_type == SEL_BY_NBR)
    {
        stmt->setString(1,my_nbr);
    }
    else if(op_type == SEL_BY_SERV_ID)
    {
        stmt->setNumber(1,m_serv_id);
    }
}

ST_SERV_IDENTIFICATION ServIdentification::getRandomServIdentInfo()
{
    op_type=SEL_RANDOM;
    string sql="SELECT SERV_ID,AGREEMENT_ID,ACC_NBR,TO_CHAR(EFF_DATE,'YYYYMMDD'),TO_CHAR(EXP_DATE,'YYYYMMDD') "
        "FROM SERV_IDENTIFICATION SAMPLE(10) "
        "WHERE ROWNUM<2 ";
    setSQL(sql);

    executeQuery();

    return serv_identification;
}

vector<ST_SERV_IDENTIFICATION> ServIdentification::getMultiRandomServIdentInfo()
{
    op_type=SEL_MULTI_RANDOM;
    string sql="SELECT * FROM "
        "(SELECT SERV_ID,AGREEMENT_ID,ACC_NBR,TO_CHAR(EFF_DATE,'YYYYMMDD'),TO_CHAR(EXP_DATE,'YYYYMMDD') "
        "FROM SERV_IDENTIFICATION ORDER BY DBMS_RANDOM.RANDOM) "
        "WHERE ROWNUM<500000 ";
    setSQL(sql);

    executeQuery();

    return v_data;
}

ST_SERV_IDENTIFICATION ServIdentification::getServIdentInfoByNBR(string nbr)
{
    op_type=SEL_BY_NBR;
    my_nbr=nbr;
    serv_identification.m_acc_nbr="";
    setSQL("SELECT SERV_ID,AGREEMENT_ID,ACC_NBR,TO_CHAR(EFF_DATE,'YYYYMMDD'),TO_CHAR(EXP_DATE,'YYYYMMDD') "
                " FROM SERV_IDENTIFICATION "
                " WHERE ACC_NBR=:ACC_NBR ");
    executeQuery();

    return serv_identification;
}

ST_SERV_IDENTIFICATION ServIdentification::getServIdentInfoByServId(long serv_id)
{
    op_type=SEL_BY_SERV_ID;
    m_serv_id=serv_id;

    setSQL("SELECT SERV_ID,AGREEMENT_ID,ACC_NBR,TO_CHAR(EFF_DATE,'YYYYMMDD'),TO_CHAR(EXP_DATE,'YYYYMMDD') "
                " FROM SERV_IDENTIFICATION "
                " WHERE SERV_ID=:SERV_ID");
    executeQuery();

    return serv_identification;
}

void ServIdentification::doParse()
{
    serv_identification.m_serv_id = (long)rset->getNumber(1);
    serv_identification.m_agreement_id = (long)rset->getNumber(2);
    serv_identification.m_acc_nbr = rset->getString(3);
    serv_identification.m_eff_date = rset->getString(4);
    serv_identification.m_exp_date = rset->getString(5);

    if(op_type==SEL_MULTI_RANDOM)
    {
        v_data.push_back(serv_identification);
    }
}
