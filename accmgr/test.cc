#include "OracleDB.hh"
#include "DBStruct.hh"
#include "Sequence.hh"
#include "Serv.hh"
#include "Cust.hh"
#include "Acct.hh"
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "Name.hh"
//static const string first_name[] = { "赵", "钱", "孙", "李", "周", "吴", "郑", "王", "冯", "陈", "褚", "卫", "蒋", "沈", "韩", "杨", "朱", "秦", "尤", "许", "何", "吕", "张", "孔", "曹", "严", "垡", "金", "魏", "陶", "姜", "戚", "谢", "邹", "窦", "章", "苏", "葛", "潘", "范", "彭", "郎", "鲁", "韦", "马", "苗", "花", "方", "俞", "任", "袁", "柳", "鲍", "史", "唐", "费", "薛", "雷", "贺", "汤", "滕", "殷", "罗", "齐", "郝", "毕", "安", "常", "于", "曲", "傅", "康", "伍", "余", "顾", "孟", "黄", "穆", "萧", "姚", "邵", "汪", "祁", "毛", "臧", "成", "戴", "宋", "庞", "熊", "纪", "舒", "项", "祝", "董", "梁", "杜", "阮", "蓝", "闵", "季", "贾", "路", "江", "颜", "郭", "梅", "林", "刁", "钟", "徐", "邱", "骆", "高", "夏", "蔡", "田", "樊", "胡", "兰", "万", "管", "占", "莫", "丁", "邓", "洪", "石", "崔", "龚", "程", "裴", "邢", "陆", "左", "段", "焦", "谷", "车", "侯", "宁", "武", "刘", "龙", "叶", "景", "詹", "黎", "白", "宴", "赖", "直", "蒙", "乔", "党", "翟", "谭", "由", "冉", "桑", "牛", "边", "温", "庄", "楚", "阎", "涂", "商", "迟", "官", "向", "易", "廖", "耿", "匡", "文", "欧", "聂", "曾", "关", "岳", "丛", "隋", "苟", "奚", "皮", "娄", "霍", "虞", "包", "班", "仲", "仇", "屠", "闻", "艾", "房", "濮", "尚", "柴", "连", "满", "寇", "师", "巩", "鞠", "竺", "郁", "欧阳", "司马", "诸葛", "上官", "夏侯", "东方", "长孙"};
//static const string second_name[] = { "汉","皇","重","色","思","倾","国","御","宇","多","年","求","不","得","杨","家","有","女","初","长","成","养","在","深","闺","人","未","识","天","生","丽","质","难","自","弃","一","朝","选","在","君","王","侧","回","眸","一","笑","百","媚","生","六","宫","粉","黛","无","颜","色","春","寒","赐","浴","华","清","池","温","泉","水","滑","洗","凝","脂","侍","儿","扶","起","娇","无","力","始","是","新","承","恩","泽","时","云","鬓","花","颜","金","步","摇","芙","蓉","帐","暖","度","春","宵","春","宵","苦","短","日","高","起","从","此","君","王","不","早","朝","承","欢","侍","宴","无","闲","暇","春","从","春","游","夜","专","夜","后","宫","佳","丽","三","千","人","三","千","宠","爱","在","一","身","金","屋","妆","成","娇","侍","夜","玉","楼","宴","罢","醉","和","春","姊","妹","弟","兄","皆","列","土","可","怜","光","彩","生","门","户","遂","令","天","下","父","母","心","不","重","生","男","重","生","女","骊","宫","高","处","入","青","云","仙","乐","风","飘","处","处","闻","缓","歌","谩","舞","凝","丝","竹","尽","日","君","王","看","不","足","渔","阳","鼙","鼓","动","地","来","惊","破","霓","裳","羽","衣","曲","九","重","城","阙","烟","尘","生","千","乘","万","骑","西","南","行","翠","华","摇","摇","行","复","止","西","出","都","门","百","余","里","六","军","不","发","无","奈","何","宛","转","蛾","眉","马","前","死","花","钿","委","地","无","人","收","翠","翘","金","雀","玉","搔","头","君","王","掩","面","救","不","得","回","看","血","泪","相","和","流","黄","埃","散","漫","风","萧","索","云","栈","萦","纡","登","剑","阁","峨","嵋","山","下","少","人","行","旌","旗","无","光","日","色","薄","蜀","江","水","碧","蜀","山","青","圣","主","朝","朝","暮","暮","情","行","宫","见","月","伤","心","色","夜","雨","闻","铃","肠","断","声","天","旋","地","转","回","龙","驭","到","此","踌","躇","不","能","去","马","嵬","坡","下","泥","土","中","不","见","玉","颜","空","死","处","君","臣","相","顾","尽","沾","衣","东","望","都","门","信","马","归","归","来","池","苑","皆","依","旧","太","液","芙","蓉","未","央","柳","芙","蓉","如","面","柳","如","眉","对","此","如","何","不","泪","垂","春","风","桃","李","花","开","日","秋","雨","梧","桐","叶","落","时","西","宫","南","内","多","秋","草","落","叶","满","阶","红","不","扫","梨","园","弟","子","白","发","新","椒","房","阿","监","青","娥","老","夕","殿","萤","飞","思","悄","然","孤","灯","挑","尽","未","成","眠","迟","迟","钟","鼓","初","长","夜","耿","耿","星","河","欲","曙","天","鸳","鸯","瓦","冷","霜","华","重","翡","翠","衾","寒","谁","与","共","悠","悠","生","死","别","经","年","魂","魄","不","曾","来","入","梦","临","邛","道","士","鸿","都","客","能","以","精","诚","致","魂","魄","为","感","君","王","辗","转","思","遂","教","方","士","殷","勤","觅","排","空","驭","气","奔","如","电","升","天","入","地","求","之","遍","上","穷","碧","落","下","黄","泉","两","处","茫","茫","皆","不","见","忽","闻","海","上","有","仙","山","山","在","虚","无","缥","渺","间","楼","阁","玲","珑","五","云","起","其","中","绰","约","多","仙","子","中","有","一","人","字","太","真","雪","肤","花","貌","参","差","是","金","阙","西","厢","叩","玉","扃","转","教","小","玉","报","双","成","闻","道","汉","家","天","子","使","九","华","帐","里","梦","魂","惊","揽","衣","推","枕","起","徘","徊","珠","箔","银","屏","迤","逦","开","云","鬓","半","偏","新","睡","觉","花","冠","不","整","下","堂","来","风","吹","仙","袂","飘","飘","举","犹","似","霓","裳","羽","衣","舞","玉","容","寂","寞","泪","阑","干","梨","花","一","枝","春","带","雨","含","情","凝","睇","谢","君","王","一","别","音","容","两","渺","茫","昭","阳","殿","里","恩","爱","绝","蓬","莱","宫","中","日","月","长","回","头","下","望","人","寰","处","不","见","长","安","见","尘","雾","惟","将","旧","物","表","深","情","钿","合","金","钗","寄","将","去","钗","留","一","股","合","一","扇","钗","擘","黄","金","合","分","钿","但","教","心","似","金","钿","坚","天","上","人","间","会","相","见","临","别","殷","勤","重","寄","词","词","中","有","誓","两","心","知","七","月","七","日","长","生","殿","夜","半","无","人","私","语","时","在","天","愿","作","比","翼","鸟","在","地","愿","为","连","理","枝","天","长","地","久","有","时","尽","此","恨","绵","绵","无","绝","期"};

int main()
{
    int first_size=215;
    int second_size=840;
    srand( (unsigned)time( NULL ) ); 

    OracleDB *db = new OracleDB();
    db->connectToDB();

    Sequence seq;
    seq.setConnection(db->getConnection());

    Serv my_serv;
    my_serv.setConnection(db->getConnection());

    Cust my_cust;
    my_cust.setConnection(db->getConnection());

    Acct my_acct;
    my_acct.setConnection(db->getConnection());

    long region_id = seq.getRegionId();
    long agreement_id = seq.getAgreementId();
    long product_id = seq.getScardvcsn();
    long billing_cycle_type_id = seq.getScardvcsn();
    long band_id = seq.getScardvcsn();
    long party_id = seq.getPartyId();

    Name name;
    for(int i=0;i<5;i++)
    {
        long serv_id = seq.getServId();
        long acct_id = seq.getAcctId();
        long cust_id = seq.getCustId();
        long family_id = seq.getScardvcsn();
        long cust_location= seq.getScardvcsn();

        string my_name=name.getName();
        my_serv.serv.m_serv_id=serv_id;
        my_serv.serv.m_agreement_id=agreement_id;
        my_serv.serv.m_cust_id=acct_id;
        my_serv.serv.m_product_id=product_id;
        my_serv.serv.m_billing_cycle_type_id=billing_cycle_type_id;
        my_serv.serv.m_product_family_id=family_id;
        my_serv.serv.m_state="0";
        my_serv.serv.m_region_id=region_id;
        my_serv.serv.m_band_id=band_id;
        my_serv.insertData();

        my_cust.cust.m_cust_id=cust_id;
        my_cust.cust.m_party_role_id=party_id;
        my_cust.cust.m_cust_name=my_name;
        my_cust.cust.m_cust_type="01";
        my_cust.cust.m_cust_location=cust_location;
        my_cust.cust.m_is_vip="N";
        my_cust.cust.m_cust_code="A";
        my_cust.cust.m_state="0";
        my_cust.insertData();


        my_acct.acct.m_acct_id=acct_id;
        my_acct.acct.m_cust_id=cust_id;
        my_acct.acct.m_acct_name=my_name;
        my_acct.acct.m_address_id=seq.getAddressId();
        ;
        my_acct.acct.m_state="0";
        my_acct.acct.m_acct_pwd="&8re@31";
        my_acct.acct.m_region_id=region_id;
        my_acct.acct.m_acct_type="10";
        my_acct.acct.m_owe_min_ym=201401;
        my_acct.acct.m_owe_fee=0;
        my_acct.insertData();

        if(i%200==0) db->commit();
    }
    db->disConnectFromDB();
    return 0;
}
