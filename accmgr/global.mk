CC_FLAGS= -g -Wall
CC=g++
AR_CMD=ar -rv

SUBDIRS=db pub biz thrift main

#define libs path
BOSS_LIB_PATH=$(BOSS_HOME)/libs/

#define database include file path
DB_INCLUDE=$(BOSS_HOME)/db/ 
PUB_INCLUDE=$(BOSS_HOME)/pub/ 
BIZ_INCLUDE=$(BOSS_HOME)/biz/ 
BOSS_THRIFT_INCLUDE=$(BOSS_HOME)/thrift/

#thrift dir
THRIFT_INCLUDE=/usr/local/include/thrift


CC_INCLDIR=-I. \
		   -I$(ORACLE_HOME)/rdbms/public/ \
		   -I$(THRIFT_INCLUDE)/ \
           -I$(BOSS_THRIFT_INCLUDE)/ \
           -I$(BOSS_HOME)/3rd/ \
		   -I$(DB_INCLUDE) \
		   -I$(PUB_INCLUDE) \
		   -I$(BIZ_INCLUDE) \
		   -I/usr/include

#ORA_LIBS=$(ORACLE_HOME)/lib -locci -lsqlplus
ORA_LIBS=$(ORACLE_HOME)/lib -locci -lclntsh
THRIFT_LIBS=/usr/local/lib -lthrift
BOSS_LIBS=$(BOSS_LIB_PATH)/ -lbiz -ldb -lpub -lbossthrift

LIBS= -L$(BOSS_LIBS) -L$(ORA_LIBS) -L$(THRIFT_LIBS) -lpthread
