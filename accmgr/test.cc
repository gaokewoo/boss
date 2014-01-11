#include "OracleDB.hh"
#include "DBStruct.hh"
#include "Sequence.hh"
#include "Serv.hh"


int main()
{
   OracleDB *db = new OracleDB();
   db->connectToDB();
   //Sequence seq;
   //seq.setConnection(db->getConnection());

   Serv srv;
   srv.setConnection(db->getConnection());
   srv.serv.m_serv_id=2;
   srv.serv.m_agreement_id=2;
   srv.serv.m_cust_id=2;
   srv.serv.m_product_id=2;
   srv.serv.m_billing_cycle_type_id=2;
   srv.serv.m_product_family_id=2;
   srv.serv.m_state="12";
   srv.serv.m_region_id=2;
   srv.serv.m_band_id=2;
   srv.insertData();
   db->commit();
   db->disConnectFromDB();
   return 0;
}
