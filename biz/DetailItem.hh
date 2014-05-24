#ifndef __DETAILITEM_HH__
#define __DETAILITEM_HH__

#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "OracleDB.hh"
#include "DBStruct.hh"
#include "FetchNbr.hh"
#include "log4z/log4z.h"

using namespace zsummer::log4z;

class DetailItem
{
public:
    DetailItem(LoggerId logId);
    ~DetailItem();
    void doBiz();

private:
    LoggerId m_logId;
    OracleDB *m_db;

    static FetchNbr *fetch_nbr;
};

#endif

