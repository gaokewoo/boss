1.��sys��¼��oracle��
sqlplus / as sysdba;

2.��ʼ�޸ı���
shutdown immediate;

startup mount;

alter system enable restricted session;

alter system set job_queue_processes=0;

alter database open;

alter database character set internal_use utf8;

shutdown immediate;

startup;

