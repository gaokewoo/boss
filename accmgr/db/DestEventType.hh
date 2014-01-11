#ifndef __DESTEVENTTYPE__
#define __DESTEVENTTYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DestEventType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_DEST_EVENT_TYPE dest_event_type;

private:
    static string insSQL;
};
#endif
