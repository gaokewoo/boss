namespace cpp PaymentInterface
    
include "BossData.thrift" 

service Payment{   

    bool subscribe(1: BossData.Payment datas);

}  
