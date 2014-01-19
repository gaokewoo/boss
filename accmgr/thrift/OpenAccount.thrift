namespace cpp BossInterface
    
include "BossData.thrift"  
    
service OpenAccountServlet {   
        
    bool Sender(1: list<BossData.OpenAccount> datas);
        
    oneway void Sender2(1: list<BossData.OpenAccount> datas);
        
}  
