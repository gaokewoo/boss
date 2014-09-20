#!/bin/bash
#�����������ű�
#�������ļ�$BOSS_HOME/script/db/create_index.cfg�ж�ȡ��Ҫ�������ļ�¼
#�����źͷֺŽ��н���
#��һ���ֶ�Ϊ������
#�ڶ����ֶ�Ϊ���ӵ����
#�������ֶ�Ϊԭʼ������
#���ĸ��ֶ�Ϊ��ռ�����
#������ֶ�Ϊ��������
#�������ֶ�Ϊ�����ֶ�
#���߸��ֶ�Ϊ��������

if [  $# -ne "1" ]
then
	echo "����������������ͬ���"
	echo "usage: $0 [�����ʶλ 0��ִ�� 1�����ɴ������]"
	exit 1
fi
create_flag=$1

BOSS_HOME=../../
ORACLEID=`$BOSS_HOME/script/db/get_globalpara.sh|grep ORACLEID|awk -F= '{print $2}'`
year=`$BOSS_HOME/script/db/get_globalpara.sh|grep YEAR|awk -F= '{print $2}'`
year_2=`$BOSS_HOME/script/db/get_globalpara.sh|grep YEAR|awk -F= '{print $2}'|cut -b 3-`

#ȡϵͳʱ��
sysdate=`date +%Y%m%d%H%M`

echo $ORACLEID
echo $year
echo $year_2

create_index()
{
	if [ "$3" = "Y" ]
	then
		echo -e "create UNIQUE index $1"
		sql="create UNIQUE index $2;"
	else
		echo -e "create index $1"
		sql="create index $2;"
	fi

	if [ $create_flag -eq "1" ]
	then
		echo -e "$sql" >> $BOSS_HOME/script/db/create_index.sql.$sysdate
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

#����1Ϊ<<<����>>>���µ�����
fun_type1()
{
	table_space_new=$table_space"_IDX"
	
	full_index_name="$index_name ON $table_name \n($index_column)"
	table_index_tmp="$index_name ON $table_name \n($index_column)"

	create_index "$table_index_tmp" "$full_index_name" "$index_typae"
}

#����2Ϊ<<<��>>>���µ�����
fun_type2()
{
	month=1
	while [ $month -lt 13 ]
	do
		str_month=`echo $month|awk '{printf "%02d\n",$1}'`
		index_name_new="$index_name$year_2$str_month"

		table_space_new=$table_space$str_month"_IDX"
		table_name_new=$table_name$year$str_month
		
		full_index_name="$index_name_new ON $table_name_new \n($index_column)"
		table_index_tmp="$index_name_new ON $table_name_new \n($index_column)"

		create_index "$table_index_tmp" "$full_index_name" "$index_typae"

		month=`expr $month + 1`
	done
}

#�������ļ�,ѭ������ÿһ����¼
while [ $year -lt 2016 ]
do
	echo "CUR YEAR = $year"
	for record in `cat $BOSS_HOME/script/db/create_index.cfg`
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
			if [ $year -eq 2010 ]
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
