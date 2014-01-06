#批量建索引脚本
#从配置文件$ACCMGR_HOME/cfg/create_index.cfg中读取需要建索引的记录
#按逗号和分号进行解析
#第一个字段为表类型
#第二个字段为表的拥有者
#第三个字段为原始表名称
#第四个字段为表空间名称
#第五个字段为索引名称
#第六个字段为索引字段
#第七个字段为索引类型

if [  $# -ne "1" ]
then
	echo "功能描述：批量建同义词"
	echo "usage: $0 [处理标识位 0：执行 1：生成创建语句]"
	exit 1
fi
create_flag=$1

ORACLEID=`$ACCMGR_HOME/shell/get_globalpara.sh|grep ORACLEID|awk -F= '{print $2}'`
year=`$ACCMGR_HOME/shell/get_globalpara.sh|grep YEAR|awk -F= '{print $2}'`
year_2=`$ACCMGR_HOME/shell/get_globalpara.sh|grep YEAR|awk -F= '{print $2}'|cut -b 3-`

#取系统时间
echo `date +%Y%m%d%H%M`|read sysdate

echo $ORACLEID
echo $year
echo $year_2

create_index()
{
	if [ "$3" = "Y" ]
	then
		echo "create UNIQUE index $1"
		echo "......................."
		sql="create UNIQUE index $2;"
	else
		echo "create index $1"
		echo "......................"
		sql="create index $2;"
	fi

	if [ $create_flag -eq "1" ]
	then
		echo "$sql" >> $ACCMGR_HOME/data/create_sql/create_index$sysdate
		echo "...................." >> $ACCMGR_HOME/data/create_sql/create_index$sysdate
	else
		echo "	set echo off\n
				set feedback off\n
				set heading off\n
				set newpage 0\n
				set pagesize 0\n
				$sql\n
				exit;\n"|sqlplus -s $ORACLEID
	fi
}

#类型1为<<<不分>>>年月的索引
fun_type1()
{
	table_space_new=$table_space"_IDX"
	
	full_index_name="$owner.$index_name ON $owner.$table_name \n($index_column) \n$table_space_new"
	table_index_tmp="$owner.$index_name ON $owner.$table_name \n($index_column) \n$table_space_new"

	create_index "$table_index_tmp" "$full_index_name" "$index_typae"
}

#类型2为<<<分>>>年月的索引
fun_type2()
{
	month=1
	while [ $month -lt 13 ]
	do
		str_month=`echo $month|awk '{printf "%02d\n",$1}'`
		index_name_new="$index_name$year_2$str_month"

		table_space_new=$table_space$str_month"_IDX"
		table_name_new=$table_name$year$str_month
		
		full_index_name="$owner.$index_name_new ON $owner.$table_name_new \n($index_column) \n$table_space_new"
		table_index_tmp="$owner.$index_name_new ON $owner.$table_name_new \n($index_column) \n$table_space_new"

		create_index "$table_index_tmp" "$full_index_name" "$index_typae"

		month=`expr $month + 1`
	done
}

#读配置文件,循环处理每一条记录
while [ $year -lt 2011 ]
do
	echo "CUR YEAR = $year"
	for record in `cat $ACCMGR_HOME/cfg/create_index.cfg`
	do
		comment=`echo $record | cut -b 1-1`
		if [ "$comment" = "#" ]
		then
			continue
		fi

		if [ "${comment:=null}" = "null" ]
		then
			echo "$comment"
			continue
		fi

		type=`echo $record|awk -F';' '{print $1}'`
		owner=`echo $record|awk -F';' '{print $2}'`
		table_name=`echo $record|awk -F';' '{print $3}'`
		table_space="TABLESPACE "`echo $record|awk -F';' '{print $4}'`
		index_name=`echo $record|awk -F';' '{print $5}'`
		index_column=`echo $record|awk -F';' '{print $6}'`
		index_typae=`echo $record|awk -F';' '{print $7}'`

		if [ "$table_space" = "TABLESPACE " ]
		then
			table_space=""
		fi

		flag=0
		if [ $type -eq "1" ]
		then
			if [ $year -eq 2000 ]
			then
				flag=1
				fun_type1
				continue
			else
				continue
			fi
		fi

		if [ $type -eq "2" ]
		then
			flag=1
			fun_type2
			continue
		fi

		if [ $flag -eq "0" ]
		then
			echo "table_name=[$table_name]type=[$type] is wrong,confirm it please."
			exit 1
		fi

	done

echo "DO THE NEXT YEAR!"
year=`expr $year + 1`
year_2=`expr $year_2 + 1`
echo "DO THE NEXT YEAR IS $year!"
done
