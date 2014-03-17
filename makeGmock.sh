#!/bin/bash
cd $BOSS_DEV_HOME/gmock
if [ ! -f gmock_main.a ]; then
    cd make
    make
    cp gmock_main.a ../
fi

