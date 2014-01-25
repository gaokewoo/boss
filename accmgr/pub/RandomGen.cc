#include "RandomGen.hh"

RandomGen::RandomGen()
{
    srand( (unsigned)time( NULL ) ); 
    id.insert(make_pair(410101,"河南省郑州市市辖区"));
    id.insert(make_pair(410102,"河南省郑州市中原区"));
    id.insert(make_pair(410103,"河南省郑州市二七区"));
    id.insert(make_pair(410104,"河南省郑州市管城回族区"));
    id.insert(make_pair(410105,"河南省郑州市金水区"));
    id.insert(make_pair(410106,"河南省郑州市上街区"));
    id.insert(make_pair(410108,"河南省郑州市惠济区"));
    id.insert(make_pair(410122,"河南省中牟县"));
    id.insert(make_pair(410181,"河南省巩义市"));
    id.insert(make_pair(410182,"河南省荥阳市"));
    id.insert(make_pair(410183,"河南省新密市"));
    id.insert(make_pair(410184,"河南省新郑市"));
    id.insert(make_pair(410185,"河南省登封市"));
    id.insert(make_pair(410201,"河南省开封市市辖区"));
    id.insert(make_pair(410202,"河南省开封市龙亭区"));
    id.insert(make_pair(410203,"河南省开封市顺河回族区"));
    id.insert(make_pair(410204,"河南省开封市鼓楼区"));
    id.insert(make_pair(410205,"河南省开封市禹王台区"));
    id.insert(make_pair(410211,"河南省开封市金明区"));
    id.insert(make_pair(410221,"河南省杞县"));
    id.insert(make_pair(410222,"河南省通许县"));
    id.insert(make_pair(410223,"河南省尉氏县"));
    id.insert(make_pair(410224,"河南省开封县"));
    id.insert(make_pair(410225,"河南省兰考县"));
    id.insert(make_pair(410301,"河南省洛阳市市辖区"));
    id.insert(make_pair(410302,"河南省洛阳市老城区"));
    id.insert(make_pair(410303,"河南省洛阳市西工区"));
    id.insert(make_pair(410304,"河南省洛阳市回族区"));
    id.insert(make_pair(410305,"河南省洛阳市涧西区"));
    id.insert(make_pair(410306,"河南省洛阳市吉利区"));
    id.insert(make_pair(410311,"河南省洛阳市洛龙区"));
    id.insert(make_pair(410322,"河南省孟津县"));
    id.insert(make_pair(410323,"河南省新安县"));
    id.insert(make_pair(410324,"河南省栾川县"));
    id.insert(make_pair(410325,"河南省嵩县"));
    id.insert(make_pair(410326,"河南省汝阳县"));
    id.insert(make_pair(410327,"河南省宜阳县"));
    id.insert(make_pair(410328,"河南省洛宁县"));
    id.insert(make_pair(410329,"河南省伊川县"));
    id.insert(make_pair(410381,"河南省偃师市"));
    id.insert(make_pair(410401,"河南省平顶山市市辖区"));
    id.insert(make_pair(410402,"河南省平顶山市新华区"));
    id.insert(make_pair(410403,"河南省平顶山市卫东区"));
    id.insert(make_pair(410404,"河南省平顶山市石龙区"));
    id.insert(make_pair(410411,"河南省平顶山市湛河区"));
    id.insert(make_pair(410421,"河南省宝丰县"));
    id.insert(make_pair(410422,"河南省叶县"));
    id.insert(make_pair(410423,"河南省鲁山县"));
    id.insert(make_pair(410425,"河南省郏县"));
    id.insert(make_pair(410481,"河南省舞钢市"));
    id.insert(make_pair(410482,"河南省汝州市"));
    id.insert(make_pair(410501,"河南省安阳市市辖区"));
    id.insert(make_pair(410502,"河南省安阳市文峰区"));
    id.insert(make_pair(410503,"河南省安阳市北关区"));
    id.insert(make_pair(410505,"河南省安阳市殷都区"));
    id.insert(make_pair(410506,"河南省安阳市龙安区"));
    id.insert(make_pair(410522,"河南省安阳县"));
    id.insert(make_pair(410523,"河南省汤阴县"));
    id.insert(make_pair(410526,"河南省滑县"));
    id.insert(make_pair(410527,"河南省内黄县"));
    id.insert(make_pair(410581,"河南省林州市"));
    id.insert(make_pair(410601,"河南省鹤壁市市辖区"));
    id.insert(make_pair(410602,"河南省鹤壁市鹤山区"));
    id.insert(make_pair(410603,"河南省鹤壁市山城区"));
    id.insert(make_pair(410611,"河南省鹤壁市淇滨区"));
    id.insert(make_pair(410621,"河南省浚县"));
    id.insert(make_pair(410622,"河南省淇县"));
    id.insert(make_pair(410701,"河南省新乡市市辖区"));
    id.insert(make_pair(410702,"河南省新乡市红旗区"));
    id.insert(make_pair(410703,"河南省新乡市卫滨区"));
    id.insert(make_pair(410704,"河南省新乡市凤泉区"));
    id.insert(make_pair(410711,"河南省新乡市牧野区"));
    id.insert(make_pair(410721,"河南省新乡县"));
    id.insert(make_pair(410724,"河南省获嘉县"));
    id.insert(make_pair(410725,"河南省原阳县"));
    id.insert(make_pair(410726,"河南省延津县"));
    id.insert(make_pair(410727,"河南省封丘县"));
    id.insert(make_pair(410728,"河南省长垣县"));
    id.insert(make_pair(410781,"河南省卫辉市"));
    id.insert(make_pair(410782,"河南省辉县市"));
    id.insert(make_pair(410801,"河南省焦作市市辖区"));
    id.insert(make_pair(410802,"河南省焦作市解放区"));
    id.insert(make_pair(410803,"河南省焦作市中站区"));
    id.insert(make_pair(410804,"河南省焦作市马村区"));
    id.insert(make_pair(410811,"河南省焦作市山阳区"));
    id.insert(make_pair(410821,"河南省修武县"));
    id.insert(make_pair(410822,"河南省博爱县"));
    id.insert(make_pair(410823,"河南省武陟县"));
    id.insert(make_pair(410825,"河南省温县"));
    id.insert(make_pair(410881,"河南省济源市"));
    id.insert(make_pair(410882,"河南省沁阳市"));
    id.insert(make_pair(410883,"河南省孟州市"));
    id.insert(make_pair(410901,"河南省濮阳市市辖区"));
    id.insert(make_pair(410902,"河南省濮阳市华龙区"));
    id.insert(make_pair(410922,"河南省清丰县"));
    id.insert(make_pair(410923,"河南省南乐县"));
    id.insert(make_pair(410926,"河南省范县"));
    id.insert(make_pair(410927,"河南省台前县"));
    id.insert(make_pair(410928,"河南省濮阳县"));
    id.insert(make_pair(411001,"河南省许昌市市辖区"));
    id.insert(make_pair(411002,"河南省许昌市魏都区"));
    id.insert(make_pair(411023,"河南省许昌县"));
    id.insert(make_pair(411024,"河南省鄢陵县"));
    id.insert(make_pair(411025,"河南省襄城县"));
    id.insert(make_pair(411081,"河南省禹州市"));
    id.insert(make_pair(411082,"河南省长葛市"));
    id.insert(make_pair(411100,"河南省漯河市"));
    id.insert(make_pair(411101,"河南省漯河市市辖区"));
    id.insert(make_pair(411102,"河南省漯河市源汇区"));
    id.insert(make_pair(411103,"河南省漯河市郾城区"));
    id.insert(make_pair(411104,"河南省漯河市召陵区"));
    id.insert(make_pair(411121,"河南省舞阳县"));
    id.insert(make_pair(411122,"河南省临颍县"));
    id.insert(make_pair(411201,"河南省三门峡市市辖区"));
    id.insert(make_pair(411202,"河南省三门峡市湖滨区"));
    id.insert(make_pair(411221,"河南省渑池县"));
    id.insert(make_pair(411222,"河南省陕县"));
    id.insert(make_pair(411224,"河南省卢氏县"));
    id.insert(make_pair(411281,"河南省义马市"));
    id.insert(make_pair(411282,"河南省灵宝市"));
    id.insert(make_pair(411301,"河南省南阳市市辖区"));
    id.insert(make_pair(411302,"河南省南阳市宛城区"));
    id.insert(make_pair(411303,"河南省南阳市卧龙区"));
    id.insert(make_pair(411321,"河南省南召县"));
    id.insert(make_pair(411322,"河南省方城县"));
    id.insert(make_pair(411323,"河南省西峡县"));
    id.insert(make_pair(411324,"河南省镇平县"));
    id.insert(make_pair(411325,"河南省内乡县"));
    id.insert(make_pair(411326,"河南省淅川县"));
    id.insert(make_pair(411327,"河南省社旗县"));
    id.insert(make_pair(411328,"河南省唐河县"));
    id.insert(make_pair(411329,"河南省新野县"));
    id.insert(make_pair(411330,"河南省桐柏县"));
    id.insert(make_pair(411381,"河南省邓州市"));
    id.insert(make_pair(411401,"河南省商丘市市辖区"));
    id.insert(make_pair(411402,"河南省商丘市梁园区"));
    id.insert(make_pair(411403,"河南省商丘市睢阳区"));
    id.insert(make_pair(411421,"河南省民权县"));
    id.insert(make_pair(411422,"河南省睢县"));
    id.insert(make_pair(411423,"河南省宁陵县"));
    id.insert(make_pair(411424,"河南省柘城县"));
    id.insert(make_pair(411425,"河南省虞城县"));
    id.insert(make_pair(411426,"河南省夏邑县"));
    id.insert(make_pair(411481,"河南省永城市"));
    id.insert(make_pair(411501,"河南省信阳市市辖区"));
    id.insert(make_pair(411502,"河南省信阳市区"));
    id.insert(make_pair(411503,"河南省信阳市平桥区"));
    id.insert(make_pair(411521,"河南省罗山县"));
    id.insert(make_pair(411522,"河南省光山县"));
    id.insert(make_pair(411523,"河南省新县"));
    id.insert(make_pair(411524,"河南省商城县"));
    id.insert(make_pair(411525,"河南省固始县"));
    id.insert(make_pair(411526,"河南省潢川县"));
    id.insert(make_pair(411527,"河南省淮滨县"));
    id.insert(make_pair(411528,"河南省息县"));
    id.insert(make_pair(411601,"河南省周口市市辖区"));
    id.insert(make_pair(411602,"河南省周口市川汇区"));
    id.insert(make_pair(411621,"河南省扶沟县"));
    id.insert(make_pair(411622,"河南省西华县"));
    id.insert(make_pair(411623,"河南省商水县"));
    id.insert(make_pair(411624,"河南省沈丘县"));
    id.insert(make_pair(411625,"河南省郸城县"));
    id.insert(make_pair(411626,"河南省淮阳县"));
    id.insert(make_pair(411627,"河南省太康县"));
    id.insert(make_pair(411628,"河南省鹿邑县"));
    id.insert(make_pair(411681,"河南省项城市"));
    id.insert(make_pair(411701,"河南省驻马店市市辖区"));
    id.insert(make_pair(411702,"河南省驻马店市驿城区"));
    id.insert(make_pair(411721,"河南省西平县"));
    id.insert(make_pair(411722,"河南省上蔡县"));
    id.insert(make_pair(411723,"河南省平舆县"));
    id.insert(make_pair(411724,"河南省正阳县"));
    id.insert(make_pair(411725,"河南省确山县"));
    id.insert(make_pair(411726,"河南省泌县"));
    id.insert(make_pair(411727,"河南省汝南县"));
    id.insert(make_pair(411728,"河南省遂平县"));
    id.insert(make_pair(411729,"河南省新蔡县"));

    region.insert(make_pair(1,"河南省郑州市"));
    region.insert(make_pair(2,"河南省开封市"));
    region.insert(make_pair(3,"河南省洛阳市"));
    region.insert(make_pair(4,"河南省平顶山市"));
    region.insert(make_pair(5,"河南省安阳市"));
    region.insert(make_pair(6,"河南省鹤壁市"));
    region.insert(make_pair(7,"河南省新乡市"));
    region.insert(make_pair(8,"河南省焦作市"));
    region.insert(make_pair(9,"河南省濮阳市"));
    region.insert(make_pair(10,"河南省许昌市"));
    region.insert(make_pair(11,"河南省漯河市"));
    region.insert(make_pair(12,"河南省三门峡市"));
    region.insert(make_pair(13,"河南省南阳市"));
    region.insert(make_pair(14,"河南省商丘市"));
    region.insert(make_pair(15,"河南省信阳市"));
    region.insert(make_pair(16,"河南省周口市"));
    region.insert(make_pair(17,"河南省驻马店市"));
}

string RandomGen::getAddress()
{
    int index = rand()%id.size();

    map<int,string>::iterator it;
    int i=0;
    for(it=id.begin();it!=id.end();i++,it++)
    {
        if(i==index)
          break;
    }

    return it->second;
}

map<int,string> RandomGen::getAllAddress()
{
    return id;
}

string RandomGen::getID()
{
    int index = rand()%id.size();

    map<int,string>::iterator it;
    int i=0;
    for(it=id.begin();it!=id.end();i++,it++)
    {
        if(i==index)
          break;
    }

    int year = 1910+rand()%100;
    int month = rand()%12;
    int day = rand()%28;
    int suffix = rand()%10000;

    char str[20]={'0'};
    sprintf(str,"%d%d%02d%02d%04d",it->first,year,month,day,suffix);

    return str;
}

string RandomGen::getNbr()
{
    string nbr_head[]={"133","153","189"};

    int index = rand()%3;
    char str[20]={'0'};
    sprintf(str,"%s%04d%04d",nbr_head[index].c_str(),rand()%10000,rand()%10000);

    return str;
}

string RandomGen::getName()
{
    return name.getName();
}


