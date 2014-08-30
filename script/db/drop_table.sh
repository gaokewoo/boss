#!/bin/bash
#批量drop表
#从配置文件$BOSS_HOME/script/db/create_table.cfg中读取需要drop表的记录
#按逗号进行解析
#第一个字段为表的拥有者
#第二个字段为原始表名称
#第三个字段为表类型
#第四个字段为表空间名称
#第五个字段为表属性值所在的文件
#对于drop表只有第一、二、三字段有有用，字段四和五没有用

if [  $# -ne "1" ]
then
	echo "功能描述：批量drop表"
	echo "usage: $0 [处理标识位 0：创建 1：生成创建语句]"
	exit 1
fi
create_flag=$1

BOSS_HOME=../../
ORACLEID=`$BOSS_HOME/script/db/get_globalpara.sh|grep ORACLEID|awk -F= '{print $2}'`
year=`$BOSS_HOME/script/db/get_globalpara.sh|grep YEAR|awk -F= '{print $2}'`

#取系统时间
sysdate=`date +%Y%m%d%H%M`

echo $ORACLEID
echo $year

drop_table()
{
	echo "drop table $1"
	
	sql="drop table $2;"
	
	if [ $create_flag -eq "1" ]
	then
		echo -e "$sql" >> $BOSS_HOME/script/db/drop_table.sql.$sysdate
	else
		echo -e "	set echo off\n
				set feedback off\n
				set heading off\n
				set newpage 0\n
				set pagesize 0\n
				$sql\n
				exit;\n"|sqlplus -s $ORACLEID
	fi
}

#类型1表名的组成“拥有者.原始表名”
#SERV
fun_type1()	
{
	full_table_name="$table_name"
	table_name_tmp="$table_name"
	
	drop_table "$table_name_tmp" "$full_table_name"
}

#类型2表名的组成“拥有者.原始表名+四位年+2位月份”
#PAYMENT200905
fun_type2()
{
	month=1
	while [ $month -lt 13 ]
	do
		str_month=`echo $month|awk '{printf "%02d\n",$1}'`
		
		full_table_name="$table_name$year$str_month"
		table_name_tmp="$table_name$year$str_month"
		
		drop_table "$table_name_tmp" "$full_table_name"
		
		month=`expr $month + 1`
	done
}

#类型3表名的组成“拥有者.原始表名+四位年+2位月份+1位后缀”
#类型3，ACCT_ITEM_TOTAL2009011
fun_type3()	
{
	month=1
	while [ $month -lt 13 ]
	do
		suffix=0
		while [ $suffix -lt 10 ]
		do
			str_month=`echo $month|awk '{printf "%02d\n",$1}'`
			str_suffix=`echo $suffix|awk '{printf "%d\n",$1}'`
			
			full_table_name="$table_name$year$str_month$str_suffix"
			table_name_tmp="$table_name$year$str_month$str_suffix"
			
			drop_table "$table_name_tmp" "$full_table_name"
			
			suffix=`expr $suffix + 1`
		done
		month=`expr $month + 1`
	done
}

#类型4表名的组成“拥有者.原始表名+四位年+2位月份+2位后缀”
#类型4，ACCT_ITEM20090111
fun_type4()	
{
	month=1
	while [ $month -lt 13 ]
	do
		suffix=0
		while [ $suffix -lt 100 ]
		do
			str_month=`echo $month|awk '{printf "%02d\n",$1}'`
			str_suffix=`echo $suffix|awk '{printf "%02d\n",$1}'`
			
			full_table_name="$table_name$year$str_month$str_suffix"
			table_name_tmp="$table_name$year$str_month$str_suffix"
			
			drop_table "$table_name_tmp" "$full_table_name"
			
			suffix=`expr $suffix + 1`
		done
		month=`expr $month + 1`
	done
}

#类型5表名的组成“拥有者.原始表名+1位后缀”
#类型5，ACCT_ITEM_DEAD1
fun_type5()	
{
	suffix=0
	while [ $suffix -lt 10 ]
	do
		str_suffix=`echo $suffix|awk '{printf "%d\n",$1}'`
		
		full_table_name="$table_name$str_suffix"
		table_name_tmp="$table_name$str_suffix"
		
		drop_table "$table_name_tmp" "$full_table_name"
		
		suffix=`expr $suffix + 1`
	done
}

#读配置文件，循环处理每一条记录
while [ $year -lt 2016 ]
do
	for record in `cat $BOSS_HOME/script/db/create_table.cfg`
	do
		comment=`echo $record | cut -b 1-1`
		if [ "$comment" = "#" ]
		then
			continue
		fi
		
		if [ "${comment:=null}" = "null" ]
		then
			continue
		fi
		
		type=`echo $record|awk -F, '{print $1}'`
		owner=`echo $record|awk -F, '{print $2}'`
		table_name=`echo $record|awk -F, '{print $3}'`

		flag=0
		if [ $type -eq "1" ]	#类型1表名的组成“拥有者.原始表名”
		then
			if [ $year -eq 2010 ]
			then
				flag=1
				fun_type1
				continue
			else
				continue
			fi
		fi 
		
		if [ $type -eq "2" ]	#类型2表名的组成“拥有者.原始表名+四位年+2位月份”
		then
			flag=1
			fun_type2
			continue
		fi
		
		if [ $type -eq "3" ]	#类型3表名的组成“拥有者.原始表名+四位年+2位月份+1位后缀”
		then
			flag=1
			fun_type3
			continue
		fi
		
		if [ $type -eq "4" ]	#类型4表名的组成“拥有者.原始表名+四位年+2位月份+2位后缀”
		then
			flag=1
			fun_type4
			continue
		fi
		
		if [ $type -eq "5" ]	#类型5表名的组成“拥有者.原始表名+1位后缀”
		then
			flag=1
			fun_type5
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
