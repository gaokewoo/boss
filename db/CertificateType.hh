#ifndef __CERTIFICATETYPE__
#define __CERTIFICATETYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CertificateType:public SQLInterface
{
public:
    void insertData();
    void emptyData();
    vector<ST_CERTIFICATE_TYPE> loadAllData();
    virtual void prepareSQL();
    virtual void doParse();

public:
    ST_CERTIFICATE_TYPE certificate_type;

private:
    int type;
    static string emptySQL;
    static string selectAllSQL;
    vector<ST_CERTIFICATE_TYPE> v_data;
    static string insSQL;
};
#endif
