#include <iostream>
#include <occi.h>

#ifndef  _DBINTERFACE__
#define __DBINTERFACE__

#define LINUXOCCI //避免函数重定义错误
using namespace std;
using namespace oracle::occi;

class DBInterface
{
public:
    DBInterface(const string & user, const string & passwd, const string db);
    DBInterface();
    virtual ~DBInterface(){};
    virtual bool connectToDB();
    virtual bool disConnectFromDB();
    virtual bool reConnectToDB();
    void setUser(const string &user);
    void setPasswd(const string &passwd);
    void setDB(const string & db);

protected:
    bool isConnect;
    string _user;
    string _passwd;
    string _db;

};

#endif

