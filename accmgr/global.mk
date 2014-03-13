CC_FLAGS= -g -Wall -fpic
CC=g++
AR_CMD=ar -rv

SUBDIRS=db pub biz thrift main

#define lib path
BOSS_LIB_PATH=$(BOSS_HOME)/boss/lib/

#define database include file path
DB_INCLUDE=$(BOSS_HOME)/boss/db/ 
PUB_INCLUDE=$(BOSS_HOME)/boss/pub/ 
BIZ_INCLUDE=$(BOSS_HOME)/boss/biz/ 
BOSS_THRIFT_INCLUDE=$(BOSS_HOME)/boss/thrift/

#thrift dir
THRIFT_INCLUDE=$(BOSS_HOME)/thrift/include/


CC_INCLDIR=-I. \
		   -I$(ORACLE_HOME)/rdbms/public/ \
		   -I$(THRIFT_INCLUDE)/ \
           -I$(BOSS_THRIFT_INCLUDE)/ \
           -I$(BOSS_HOME)/boss/3rd/ \
		   -I$(DB_INCLUDE) \
		   -I$(PUB_INCLUDE) \
		   -I$(BIZ_INCLUDE) \
		   -I/usr/include

#ORA_LIBS=$(ORACLE_HOME)/lib -locci -lsqlplus
ORA_LIBS=$(ORACLE_HOME)/lib -locci -lclntsh
THRIFT_LIBS=$(BOSS_HOME)/thrift/lib -lthrift
BOSS_LIBS=$(BOSS_LIB_PATH)/ -lbossbiz -lbossdb -lbosspub -lbossthrift

LIBS= -L$(BOSS_LIBS) -L$(ORA_LIBS) -L$(THRIFT_LIBS) -lpthread
