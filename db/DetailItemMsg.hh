#ifndef __DETAILITEMMSG__
#define __DETAILITEMMSG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DetailItemMsg:public SQLInterface
{
    public:
        void insertData();
        virtual void prepareSQL();
        virtual void doParse(){};

    public:
        ST_DETAIL_ITEM_MSG detail_item_msg;

    private:
        enum OP_TYPE {INSERT=0,EMPTY,SELECT_ALL};
        OP_TYPE type;
};
#endif
