#ifndef __OFFERITEMRELATION__
#define __OFFERITEMRELATION__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class OfferItemRelation:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_OFFER_ITEM_RELATION offer_item_relation;

private:
    static string insSQL;
};
#endif
