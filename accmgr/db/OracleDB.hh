#include "DBInterface.hh"

#ifndef __ORACLEDB__
#define __ORACLEDB__
class OracleDB:public DBInterface
{
public:
    OracleDB(const string & user, const string & passwd, const string & db);
    OracleDB();
    virtual ~OracleDB(){};
    virtual bool connectToDB();
    virtual bool disConnectFromDB();
    virtual bool reConnectToDB();

private:   
    void initializeEnv();
    void destroyEnv();
    void createConnection();
    void terminateConnection();

private:
    Environment *env;
    Connection *conn;

};

#endif

