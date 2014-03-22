#ifndef __BILLINTERFACE__
#define __BILLINTERFACE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class BillInterface:public SQLInterface
{
public:
    void insertData();
    void deleteBillInterfaceByPaymentId(long payment_id);
    virtual void prepareSQL();
    virtual void doParse();
    vector<ST_BILL_INTERFACE> loadAllData();

public:
    ST_BILL_INTERFACE bill_interface;

private:
    enum OP_TYPE {INSERT=0,SELECT_ALL,DELETE};
    OP_TYPE type;
    vector<ST_BILL_INTERFACE> v_data;
    long m_payment_id;
    static string insSQL;
};
#endif
