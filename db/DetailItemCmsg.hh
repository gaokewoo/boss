#ifndef __DETAILITEMCMSG__
#define __DETAILITEMCMSG__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DetailItemCmsg:public SQLInterface
{
    public:
        void insertData();
        virtual void prepareSQL();
        virtual void doParse(){};

    public:
        ST_DETAIL_ITEM_CMSG detail_item_cmsg;

    private:
        enum OP_TYPE {INSERT=0,EMPTY,SELECT_ALL};
        OP_TYPE type;
};
#endif
