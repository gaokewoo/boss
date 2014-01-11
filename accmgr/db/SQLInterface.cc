#include "SQLInterface.hh"

void SQLInterface::executeQurey()
{
    try
    {
        Statement *stmt=conn->createStatement(sqlStmt);
        prepareSQL();
        rset = stmt->executeQuery();
        while(rset->next())
        {
            doParse();
        }
        stmt->closeResultSet(rset);//to free resources 
    }
    catch(SQLException& sqlExcp)
    {
        cout <<__FILE__<<":"<<__func__<<":"<<__LINE__<<":"
            << "*Db Exception*,"
            << "ErrorCode=" << sqlExcp.getErrorCode()
            <<",ErrorStr=" << sqlExcp.getMessage() << endl;
    }
    catch(exception& excp)
    {
        cout <<__FILE__<<":"<<__func__<<":"<<__LINE__<<":"
            <<"*Exception*," <<excp.what() << endl;
    }
    catch(...)
    {
        cout <<__FILE__<<":"<<__func__<<":"<<__LINE__<<":"
            <<"Unknown Exception!" << endl;
    }

}


void SQLInterface::executeUpdate()
{

    try
    {
        Statement *stmt=conn->createStatement(sqlStmt);
        prepareSQL();
        stmt->executeUpdate();
        stmt->closeResultSet(rset);//to free resources 
    }
    catch(SQLException& sqlExcp)
    {
        cout <<__FILE__<<":"<<__func__<<":"<<__LINE__<<":"
            << "*Db Exception*,"
            << "ErrorCode=" << sqlExcp.getErrorCode()
            <<",ErrorStr=" << sqlExcp.getMessage() << endl;
    }
    catch(exception& excp)
    {
        cout <<__FILE__<<":"<<__func__<<":"<<__LINE__<<":"
            <<"*Exception*," <<excp.what() << endl;
    }
    catch(...)
    {
        cout <<__FILE__<<":"<<__func__<<":"<<__LINE__<<":"
            <<"Unknown Exception!" << endl;
    }
}


