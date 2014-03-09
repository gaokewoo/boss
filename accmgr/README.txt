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
cd m4-1.4.16
./configure
make
make check
make install

cd autoconf-2.68b
./configure
make
make install
make installcheck

cd thrift-0.9.1
./bootstrap.sh
./configure --prefix=/opt-boss/thrift/
make
make check
make install
#####install thrift end#########


#####install rabbitmq begin#######
#install erlang
cd otp_src_R13B03
LANG=C; export LANG #Bourne shell
./configure --prefix=/opt-boss/erlang/
make
make install

#install simplejson, Note:make sure python has been installed
cd simplejson-3.3.3
python setup.py install

#install rabbitmq, Note:make sure xmlto has been installed
cd rabbitmq-server-3.2.4
make TARGET_DIR=/opt-boss/rabbitmq SBIN_DIR=/opt-boss/rabbitmq/sbin
MAN_DIR=/opt-boss/rabbitmq/man DOC_INSTALL_DIR=/opt-boss/rabbitmq/doc install

#####install rabbitmq end#######
