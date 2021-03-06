#ifndef __DETAILITEM_HH__
#define __DETAILITEM_HH__

#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "OracleDB.hh"
#include "DBStruct.hh"
#include "FetchNbr.hh"
#include "Sequence.hh"
#include "log4z/log4z.h"
#include "RandomGen.hh"

using namespace zsummer::log4z;

class DetailItem
{
public:
    DetailItem(LoggerId logId);
    ~DetailItem();
    void doBiz(int type);
    void doVoiceBiz();
    void doMsgBiz();
    void doCmsgBiz();
    void doCringBiz();
    void doInsAcct(string nbr,int item,int fee);

private:
    LoggerId m_logId;
    OracleDB *m_db;
    Sequence m_seq;
    RandomGen generator;

    static FetchNbr *fetch_nbr;
};

#endif

