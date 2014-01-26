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


#####install thrift begin#########
#below is for installing thrift if your OS is OLE
rpm -ivh boost-devel-1.41.0-11.el6.i686.rpm zlib-devel-1.2.3-25.el6.i686.rpm python-devel-2.6.6-20.el6.i686.rpm openssl-devel-1.0.0-10.el6.i686.rpm krb5-devel-1.9-9.el6.i686.rpm libcom_err-devel-1.41.12-7.el6.i686.rpm libselinux-devel-2.0.94-5.el6.i686.rpm libsepol-devel-2.0.41-3.el6.i686.rpm keyutils-libs-devel-1.4-1.el6.i686.rpm 


cd m4-1.4.17
./configure
make
make install

rpm -ivh autoconf-2.68-2.el6.noarch.rpm --nodeps --force

cd thrift
./bootstrap.sh
./configure
make
make check
make install
#####install thrift end#########
