#include "OracleDB.hh"

int main()
{
   OracleDB *db = new OracleDB();
   db->connectToDB();
   db->getSysDate();
   db->disConnectFromDB();
   return 0;
}
