#include "OracleDB.hh"

OracleDB::OracleDB(const string & user, const string & passwd, const string & db):DBInterface(user,passwd,db),env(NULL), conn(NULL)
{
}

OracleDB::OracleDB():DBInterface(), env(NULL), conn(NULL)
{
}

void OracleDB::initializeEnv()
{
    try
    {
        env=Environment::createEnvironment(Environment::DEFAULT);
    }
    catch(SQLException& sqlExcp)
    {
        cerr << "*Db Exception*,"
            << "ErrorCode=" << sqlExcp.getErrorCode()
            <<",ErrorStr=" << sqlExcp.getMessage() << endl;
        throw(sqlExcp);
    }
    catch(exception& excp)
    {
        cerr <<"*Exception*," <<excp.what() << endl;
        throw(excp);
    }
    catch(...)
    {
        cerr <<"Unknown Exception!" << endl;
        throw;
    }
}

void OracleDB::destroyEnv()
{
    try
    {
        Environment::terminateEnvironment(env);
        env = NULL;
    }
    catch(SQLException& sqlExcp)
    {
        cerr << "*Db Exception*,"
            << "ErrorCode=" << sqlExcp.getErrorCode()
            <<",ErrorStr=" << sqlExcp.getMessage() << endl;
        throw(sqlExcp);
    }
    catch(exception& excp)
    {
        cerr <<"*Exception*," <<excp.what() << endl;
        throw(excp);
    }
    catch(...)
    {
        cerr <<"Unknown Exception!" << endl;
        throw;
    }
}


void OracleDB::createConnection()
{
    try
    {
        conn = env->createConnection(_user, _passwd, _db);
    }
    catch(SQLException& sqlExcp)
    {
        cerr << "*Db Exception*,"
            << "ErrorCode=" << sqlExcp.getErrorCode()
            <<",ErrorStr=" << sqlExcp.getMessage() << endl;
        throw(sqlExcp);
    }
    catch(exception& excp)
    {
        cerr <<"*Exception*," <<excp.what() << endl;
        throw(excp);
    }
    catch(...)
    {
        cerr <<"Unknown Exception!" << endl;
        throw;
    }

}

void OracleDB::terminateConnection()
{
    try
    {
        env->terminateConnection(conn);
        conn = NULL;
    }
    catch(SQLException& sqlExcp)
    {
        cerr << "*Db Exception*,"
            << "ErrorCode=" << sqlExcp.getErrorCode()
            <<",ErrorStr=" << sqlExcp.getMessage() << endl;
        throw(sqlExcp);
    }
    catch(exception& excp)
    {
        cerr <<"*Exception*," <<excp.what() << endl;
        throw(excp);
    }
    catch(...)
    {
        cerr <<"Unknown Exception!" << endl;
        throw;
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

