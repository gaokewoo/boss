#include "OracleDB.hh"

int main()
{
   DBInterface *db = new OracleDB();
   db->connectToDB();
   db->disConnectFromDB();
   return 0;
}
