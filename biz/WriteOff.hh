#ifndef __WRITEOFF_HH__
#define __WRITEOFF_HH__

#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "OracleDB.hh"
#include "DBStruct.hh"
#include "Sequence.hh"
#include "log4z/log4z.h"

using namespace zsummer::log4z;

class WriteOff
{
public:
    WriteOff(LoggerId logId);
    ~WriteOff();
    void doBiz();
    long getNextYm(long owe_min_ym);

private:
    Sequence m_seq;
    LoggerId m_logId;
    OracleDB *m_db;

};

#endif

