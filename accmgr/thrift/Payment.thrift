namespace cpp BossInterface
    
include "BossData.thrift" 

service Payment{   

    bool subscribe(1: BossData.Payment datas);

}  
