#/bin/bash
export ORACLE_SID=devdb
export ORACLE_BASE=/u01/app/oracle
export ORACLE_HOME=/u01/app/oracle/product/11.2.0/dbhome_1
export NLS_LANG=american_america.utf8
export BOSS_INSTALL_HOME=/opt-boss/
export PATH=$ORACLE_HOME/bin:$BOSS_INSTALL_HOME/thrift/bin/:/usr/local/bin:/usr/sbin:$PATH
export CLASSPATH=$ORACLE_HOME/JRE:$ORACLE_HOME/jlib:$ORACLE_HOME/rdbms/jlib:$ORACLE_HOME/jdk/jre/lib/ext
export SHLIB_PATH=$ORACLE_HOME/lib:$ORACLE_HOME/rdbms/lib:$ORACLE_HOME/lib:.

export BOSS_HOME=~/boss/accmgr/

export LD_LIBRARY_PATH=$ORACLE_HOME/lib:/lib:/usr/lib:$ORACLE_HOME/rdbms/lib:$ORACLE_HOME/lib32:$BOSS_HOME/lib:$BOSS_INSTALL_HOME/thrift/lib:.:$LD_LIBRARY_PATH
