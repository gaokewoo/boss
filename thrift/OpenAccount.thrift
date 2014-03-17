namespace cpp BossInterface

include "BossData.thrift"

service OpenAccountServlet
{
    bool send(1: BossData.OpenAccount data);
}
