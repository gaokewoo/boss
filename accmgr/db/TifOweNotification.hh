#ifndef __TIFOWENOTIFICATION__
#define __TIFOWENOTIFICATION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class TifOweNotification:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_TIF_OWE_NOTIFICATION tif_owe_notification;

private:
    static string insSQL;
};
#endif
