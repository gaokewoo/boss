#include "OracleDB.hh"

OracleDB::OracleDB(const string & user, const string & passwd, const string & db):DBInterface(user,passwd,db),env(NULL), conn(NULL)
{
}

OracleDB::OracleDB():DBInterface(), env(NULL), conn(NULL)
{
}

void OracleDB::initializeEnv()
{
    env=Environment::createEnvironment(Environment::DEFAULT);
}

void OracleDB::destroyEnv()
{
    Environment::terminateEnvironment(env);
    env = NULL;
}


void OracleDB::createConnection()
{
    try
    {
        conn = env->createConnection(_user, _passwd, _db);
        conn = NULL;
    }
    catch(SQLException e)
    {
        cout<<e.what()<<endl;
        throw(e);
    }

}

void OracleDB::terminateConnection()
{
    try
    {
        env->terminateConnection(conn);
    }
    catch(SQLException e)
    {
        cout<<e.what()<<endl;
        throw(e);
    }

}

bool OracleDB::connectToDB()
{
    initializeEnv();
    createConnection();
    isConnect = true;

    return true;
}

bool OracleDB::disConnectFromDB()
{
    terminateConnection();
    destroyEnv();
    isConnect = false;

    return true;
}

bool OracleDB::reConnectToDB()
{
    disConnectFromDB();
    connectToDB();
    
    return true;
}
