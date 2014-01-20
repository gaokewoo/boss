#/bin/bash

PWD=`pwd`

source $PWD/env.sh

cd $BOSS_HOME/bin
./BossMonitorServer
./OpenAccountServer


