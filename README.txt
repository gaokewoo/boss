###create installation env begin##
mkdir /opt-boss/
chown oracle:oinstall /opt-boss/
###create installation env end##

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


#####install zmq begin#######
cd libzmq
./autogen.sh
./configure --prefix=/opt-boss/libzmq/
make
make install
#####install zmq end#######

#####install glog begin#######
cd glog-0.3.3
./configure --prefix=/opt-boss/glog/
make
make install
#####install glog end#######

#####install boss begin#####
cd boss
source bossenv.sh
source env.sh
make
make install
#####install boss end#####


