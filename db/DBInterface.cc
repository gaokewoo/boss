#include "DBInterface.hh"

DBInterface::DBInterface(const string & user, const string & passwd, const string db):
    isConnect(false),
    _user(user),
    _passwd(passwd),
    _db(db)
{
}

DBInterface::DBInterface():
    isConnect(false),
    _user("accmgr"),
    _passwd("accmgr"),
    _db("127.0.0.1:1521/devdb")
{
}

bool DBInterface::connectToDB()
{
    return false;
}

bool DBInterface::disConnectFromDB()
{
    return false;
}

bool DBInterface::reConnectToDB()
{
    return false;
}

void DBInterface::setUser(const string & user)
{
    _user=user;
}

void DBInterface::setPasswd(const string & passwd)
{
    _passwd=passwd;
}

void DBInterface::setDB(const string & db)
{
    _db=db;
}

