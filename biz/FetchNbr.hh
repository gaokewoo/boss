#ifndef __FETCHNBR_HH__
#define __FETCHNBR_HH__

#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "OracleDB.hh"
#include "DBStruct.hh"
#include "log4z/log4z.h"
#include "ServIdentification.hh"

using namespace zsummer::log4z;

class FetchNbr
{
public:
    FetchNbr(LoggerId logId);
    ~FetchNbr();
    string doBiz();
    static void* loadingData(void * owner);
    void loadingData();

private:
    LoggerId m_logId;
    OracleDB *m_db;
    pthread_t threadId;
    vector<ST_SERV_IDENTIFICATION> v_data;
    pthread_rwlock_t lock;
};

#endif

