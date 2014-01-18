#/bin/bash
export ORACLE_SID=devdb
export ORACLE_BASE=/u01/app/oracle
export ORACLE_HOME=/u01/app/oracle/product/11.2.0/dbhome_1
export NLS_LANG=american_america.utf8
export PATH=$ORACLE_HOME/bin:/usr/local/bin:/usr/sbin:$PATH
export CLASSPATH=$ORACLE_HOME/JRE:$ORACLE_HOME/jlib:$ORACLE_HOME/rdbms/jlib:$ORACLE_HOME/jdk/jre/lib/ext
export SHLIB_PATH=$ORACLE_HOME/lib:$ORACLE_HOME/rdbms/lib:$ORACLE_HOME/lib:.
export LD_LIBRARY_PATH=$ORACLE_HOME/lib:/lib:/usr/lib:$ORACLE_HOME/rdbms/lib:$ORACLE_HOME/lib32:.

export BOSS_HOME=/home/wugk/dev/boss/accmgr/
