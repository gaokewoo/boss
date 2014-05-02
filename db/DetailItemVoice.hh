#ifndef __DETAILITEMVOICE__
#define __DETAILITEMVOICE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class DetailItemVoice:public SQLInterface
{
    public:
        void insertData();
        virtual void prepareSQL();
        virtual void doParse(){};

    public:
        ST_DETAIL_ITEM_VOICE detail_item_voice;

    private:
};
#endif
