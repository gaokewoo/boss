#/bin/bash
export ORACLE_BASE=/oracle
export ORACLE_HOME=$ORACLE_BASE/product/11.2.0/db_1
export NLS_LANG=american_america.zhs16gbk
export ORACLE_SID=devdb
export PATH=$ORACLE_HOME/bin:/usr/local/bin:/usr/sbin:$PATH
export CLASSPATH=$ORACLE_HOME/JRE:$ORACLE_HOME/jlib:$ORACLE_HOME/rdbms/jlib:$ORACLE_HOME/jdk/jre/lib/ext
export SHLIB_PATH=$ORACLE_HOME/lib32:$ORACLE_HOME/rdbms/lib32:$ORACLE_HOME/lib:.
export LD_LIBRARY_PATH=$ORACLE_HOME/lib:/lib:/usr/lib:$ORACLE_HOME/rdbms/lib:$ORACLE_HOME/lib32:.

export BOSS_HOME=/home/wugk/boss/accmgr
