namespace cpp BossInterface
    
service FetchNbr{   

    string fetchNbr();
}  

service FetchBalance{
    double fetchBalance(1:string nbr);
}
