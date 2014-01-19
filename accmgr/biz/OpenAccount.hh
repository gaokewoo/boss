#ifndef __OPENACCOUNT_HH__
#define __OPENACCOUNT_HH__

#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "OracleDB.hh"
#include "DBStruct.hh"
#include "Sequence.hh"
#include "Serv.hh"
#include "Cust.hh"
#include "Acct.hh"
#include "Name.hh"
#include "log4z/log4z.h"

using namespace zsummer::log4z;
class OpenAccount
{
public:
    OpenAccount(LoggerId logId);
    ~OpenAccount();
    void doBiz();

private:
    LoggerId m_logId;
    OracleDB *m_db;

    Sequence m_seq;
    Serv m_serv;
    Cust m_cust;
    Acct m_acct;
};

#endif

