#include "OracleDB.hh"

#ifndef __SQLINTERFACE__
#define __SQLINTERFACE__

class SQLInterface
{
public:
    SQLInterface(){}
    SQLInterface(Connection *dbConn){ conn = dbConn; }
    virtual ~SQLInterface(){}
    void setConnection(Connection *dbConn) { conn = dbConn; }
    void executeQuery();
    void executeUpdate();

    void setSQL(string sql) { sqlStmt = sql; }
    virtual void prepareSQL(){};
    virtual void doParse(){};

protected:
    string sqlStmt;
    Statement *stmt;
    ResultSet *rset;
    Connection *conn;
};

#endif

