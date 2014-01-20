#/bin/bash

PWD=`pwd`

source $PWD/env.sh

cd $BOSS_HOME/bin
./BossMonitorClient |grep ^[1-9]|awk '{print $1}'|xargs kill

