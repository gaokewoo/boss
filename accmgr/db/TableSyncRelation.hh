#ifndef __TABLESYNCRELATION__
#define __TABLESYNCRELATION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class TableSyncRelation:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_TABLE_SYNC_RELATION table_sync_relation;

private:
    static string insSQL;
};
#endif
