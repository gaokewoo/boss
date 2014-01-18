1.用sys登录到oracle中
sqlplus / as sysdba;

2.开始修改编码
shutdown immediate;

startup mount;

alter system enable restricted session;

alter system set job_queue_processes=0;

alter database open;

alter database character set internal_use utf8;

shutdown immediate;

startup;

