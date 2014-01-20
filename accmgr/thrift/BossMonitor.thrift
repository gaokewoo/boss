namespace cpp BossInterface
    
include "BossData.thrift" 

service BossMonitor{   
        
    bool subscribe(1: BossData.BossMonitor datas);
        
    list<BossData.BossMonitor> getAll();
        
}  
