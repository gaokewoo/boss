namespace cpp BossInterface
    
include "BossData.thrift" 

service PayFee{   

    bool subscribe(1: BossData.PayFee datas);

}  
