#ifndef __FETCHBALANCE_HH__
#define __FETCHBALANCE_HH__

#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "OracleDB.hh"
#include "DBStruct.hh"
#include "log4z/log4z.h"

using namespace zsummer::log4z;

class FetchBalance
{
public:
    FetchBalance(LoggerId logId);
    ~FetchBalance();
    double doBiz(string nbr);
    long getNextYm(long owe_min_ym);

private:
    LoggerId m_logId;
    OracleDB *m_db;

};

#endif

