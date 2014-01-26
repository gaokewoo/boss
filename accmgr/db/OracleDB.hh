#include "DBInterface.hh"
#include <exception>
#include <iostream>

#ifndef __ORACLEDB__
#define __ORACLEDB__

using namespace std;

class OracleDB:public DBInterface
{
public:
    OracleDB(const string & user, const string & passwd, const string & db);
    OracleDB();
    virtual ~OracleDB(){};
    virtual bool connectToDB();
    virtual bool disConnectFromDB();
    virtual bool reConnectToDB();

    Connection * getConnection() { return conn; };
    void commit();
    void rollback();

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

