#include "Dual.hh"

string Dual::getSysDateYYYYMM()
{
    setSQL("SELECT TO_CHAR(SYSDATE,'YYYYMM') FROM DUAL");
    executeQuery();

    return data;
}

string Dual::getSysDateYYYYMMDD()
{
    setSQL("SELECT TO_CHAR(SYSDATE,'YYYYMMDD') FROM DUAL");
    executeQuery();

    return data;
}

string Dual::getSysDateYYYYMMDDHH24MISS()
{
    setSQL("SELECT TO_CHAR(SYSDATE,'YYYYMMDDHH24MISS') FROM DUAL");
    executeQuery();

    return data;
}

void Dual::doParse()
{
    data = rset->getString(1);
}
