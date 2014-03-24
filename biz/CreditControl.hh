#ifndef __CREDITCONTROL_HH__
#define __CREDITCONTROL_HH__

#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "OracleDB.hh"
#include "DBStruct.hh"
#include "log4z/log4z.h"

using namespace zsummer::log4z;

class CreditControl
{
public:
    CreditControl(LoggerId logId);
    ~CreditControl();
    void doBiz(string acc_nbr);

private:
    LoggerId m_logId;
    OracleDB *m_db;

};

#endif

