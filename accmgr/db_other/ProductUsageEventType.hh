#ifndef __PRODUCTUSAGEEVENTTYPE__
#define __PRODUCTUSAGEEVENTTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ProductUsageEventType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_PRODUCT_USAGE_EVENT_TYPE product_usage_event_type;

private:
    static string insSQL;
};
#endif
