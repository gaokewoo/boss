#ifndef __OWENOTIFICATIONINFO__
#define __OWENOTIFICATIONINFO__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OweNotificationInfo:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OWE_NOTIFICATION_INFO owe_notification_info;

private:
    static string insSQL;
};
#endif
