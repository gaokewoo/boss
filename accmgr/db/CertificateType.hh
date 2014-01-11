#ifndef __CERTIFICATETYPE__
#define __CERTIFICATETYPE__
#include "DBStruct.hh"
#include "SQLInterface.hh"

class CertificateType:public SQLInterface
{
public:
    void insertData();
    virtual void prepareSQL();
    virtual void doParse(){};

public:
    ST_CERTIFICATE_TYPE certificate_type;

private:
    static string insSQL;
};
#endif
