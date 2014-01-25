#/bin/bash

PWD=`pwd`

source $PWD/env.sh

p_num=`$PWD/status 2>&1|grep PROCESS_ID|wc -l`

if [ "$p_num" != "0" ];then
    echo "Servers already started!"
    exit 1
fi

cd $BOSS_HOME/bin
./BossMonitorServer
./OpenAccountServer

