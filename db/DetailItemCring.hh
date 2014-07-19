#ifndef __DETAILITEMCRING__
#define __DETAILITEMCRING__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DetailItemCring:public SQLInterface
{
    public:
        void insertData();
        virtual void prepareSQL();
        virtual void doParse(){};

    public:
        ST_DETAIL_ITEM_CRING detail_item_cring;

    private:
        enum OP_TYPE {INSERT=0,EMPTY,SELECT_ALL};
        OP_TYPE type;
};
#endif
