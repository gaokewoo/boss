#ifndef __FETCHNBR_HH__
#define __FETCHNBR_HH__

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

private:
    LoggerId m_logId;
    OracleDB *m_db;

};

#endif

