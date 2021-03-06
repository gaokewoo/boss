
namespace cpp BossData

struct OpenAccount
{   
    1: string nbr="",
    2: string name="",
    3: string gender="",
    4: string idNo="",
    5: string address="",
}  

struct BossMonitor
{
    1: i32 id,
    2: string name,
    3: string ip,
    4: i32 port,
    5: string status,
}

struct PayFee
{
    1: string nbr="",
    2: double fee=0,
}

struct AdjustAcctItem
{
    1: string nbr="",
    2: string ym="",
    3: double fee=0,
}
