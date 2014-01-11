#ifndef __CHNGROUPINFOCHG__
#define __CHNGROUPINFOCHG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class ChnGroupInfoChg:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CHN_GROUP_INFO_CHG chn_group_info_chg;

private:
    static string insSQL;
};
#endif
