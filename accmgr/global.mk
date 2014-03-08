CC_FLAGS= -g -Wall -fpic
CC=g++
AR_CMD=ar -rv

#SUBDIRS=db pub biz thrift main
SUBDIRS=db pub biz main

#define lib path
BOSS_LIB_PATH=$(BOSS_HOME)/lib/

#define database include file path
DB_INCLUDE=$(BOSS_HOME)/db/ 
PUB_INCLUDE=$(BOSS_HOME)/pub/ 
BIZ_INCLUDE=$(BOSS_HOME)/biz/ 
#BOSS_THRIFT_INCLUDE=$(BOSS_HOME)/thrift/
BOSS_THRIFT_INCLUDE=.

#thrift dir
#THRIFT_INCLUDE=/usr/local/include/thrift
THRIFT_INCLUDE=.


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
#THRIFT_LIBS=/usr/local/lib -lthrift
THRIFT_LIBS=.
#BOSS_LIBS=$(BOSS_LIB_PATH)/ -lbiz -ldb -lpub -lbossthrift
BOSS_LIBS=$(BOSS_LIB_PATH)/ -lbossbiz -lbossdb -lbosspub 

LIBS= -L$(BOSS_LIBS) -L$(ORA_LIBS) -L$(THRIFT_LIBS) -lpthread
