#ifndef __CONFIGDATA_HH__
#define __CONFIGDATA_HH__

#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "OracleDB.hh"
#include "DBStruct.hh"
#include "Sequence.hh"
#include "CertificateType.hh"
#include "AcctType.hh"
#include "Name.hh"
#include "log4z/log4z.h"

using namespace zsummer::log4z;
class ConfigData
{
public:
    ConfigData(LoggerId logId);
    ~ConfigData();
    void configCertificateType();
    void configAcctType();
    void doBiz();

private:
    LoggerId m_logId;
    OracleDB *m_db;

    Sequence m_seq;
    CertificateType m_certificate_type;
    AcctType m_acct_type;
};

#endif

