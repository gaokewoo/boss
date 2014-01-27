#include "SQLInterface.hh"

void SQLInterface::executeQuery()
{
    try
    {
        stmt=conn->createStatement(sqlStmt);
        prepareSQL();
        rset = stmt->executeQuery();
        while(rset->next())
        {
            doParse();
        }
        stmt->closeResultSet(rset);//to free resources 
        conn->terminateStatement(stmt);
    }
    catch(SQLException& sqlExcp)
    {
        cout <<__FILE__<<":"<<__func__<<":"<<__LINE__<<":"
            << "*Db Exception*,"
            << "ErrorCode=" << sqlExcp.getErrorCode()
            <<",ErrorStr=" << sqlExcp.getMessage() << endl;
        cout<<"SQL:"<<sqlStmt<<endl;

        throw;
    }
    catch(exception& excp)
    {
        cout <<__FILE__<<":"<<__func__<<":"<<__LINE__<<":"
            <<"*Exception*," <<excp.what() << endl;
        cout<<"SQL:"<<sqlStmt<<endl;

        throw;
    }
    catch(...)
    {
        cout <<__FILE__<<":"<<__func__<<":"<<__LINE__<<":"
            <<"Unknown Exception!" << endl;
        cout<<"SQL:"<<sqlStmt<<endl;

        throw;
    }

}


void SQLInterface::executeUpdate()
{

    try
    {
        stmt=conn->createStatement(sqlStmt);
        prepareSQL();
        stmt->executeUpdate();
        conn->terminateStatement(stmt);
    }
    catch(SQLException& sqlExcp)
    {
        cout <<__FILE__<<":"<<__func__<<":"<<__LINE__<<":"
            << "*Db Exception*,"
            << "ErrorCode=" << sqlExcp.getErrorCode()
            <<",ErrorStr=" << sqlExcp.getMessage() << endl;
        cout<<"SQL:"<<sqlStmt<<endl;

        throw;
    }
    catch(exception& excp)
    {
        cout <<__FILE__<<":"<<__func__<<":"<<__LINE__<<":"
            <<"*Exception*," <<excp.what() << endl;
        cout<<"SQL:"<<sqlStmt<<endl;

        throw;
    }
    catch(...)
    {
        cout <<__FILE__<<":"<<__func__<<":"<<__LINE__<<":"
            <<"Unknown Exception!" << endl;
        cout<<"SQL:"<<sqlStmt<<endl;

        throw;
    }
}


