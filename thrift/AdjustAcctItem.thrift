namespace cpp BossInterface

include "BossData.thrift"

service AdjustAcctItem
{
    bool send(1: BossData.AdjustAcctItem data);
}
