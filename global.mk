CC_FLAGS= -g3 -Wall -fpic
CC=g++
AR_CMD=ar -rv

SUBDIRS=tinyxml2 ds db pub biz thrift main

#define lib path
BOSS_LIB_PATH=$(BOSS_DEV_HOME)/lib/

#define database include file path
DB_INCLUDE=$(BOSS_DEV_HOME)/db/ 
PUB_INCLUDE=$(BOSS_DEV_HOME)/pub/ 
BIZ_INCLUDE=$(BOSS_DEV_HOME)/biz/ 
DS_INCLUDE=$(BOSS_DEV_HOME)/ds/ 
BOSS_THRIFT_INCLUDE=$(BOSS_DEV_HOME)/thrift/
TINYXML2_INCLUDE=$(BOSS_DEV_HOME)/tinyxml2/
BOSS_LIBS=$(BOSS_LIB_PATH)/ -lbossbiz -lbossdb -lbosspub -lbossthrift -lbossalg -ltinyxml2

#thrift dir
THRIFT_INCLUDE=$(BOSS_HOME)/thrift/include/
THRIFT_LIBS=$(BOSS_HOME)/thrift/lib -lthrift

#tinyxml2 dir

#gmock dir
GMOCK_INCLUDE=$(BOSS_DEV_HOME)/gmock/include/
GTEST_INCLUDE=$(BOSS_DEV_HOME)/gmock/gtest/include/


CC_INCLDIR=-I. \
		   -I$(ORACLE_HOME)/rdbms/public/ \
		   -I$(THRIFT_INCLUDE)/ \
		   -I$(GMOCK_INCLUDE)/ \
		   -I$(GTEST_INCLUDE)/ \
           -I$(BOSS_THRIFT_INCLUDE)/ \
           -I$(BOSS_DEV_HOME)/3rd/ \
		   -I$(DB_INCLUDE) \
		   -I$(PUB_INCLUDE) \
		   -I$(BIZ_INCLUDE) \
		   -I$(DS_INCLUDE) \
		   -I$(TINYXML2_INCLUDE) \
		   -I/usr/include

ORA_LIBS=$(ORACLE_HOME)/lib -locci -lclntsh

LIBS= -L$(BOSS_LIBS) -L$(ORA_LIBS) -L$(THRIFT_LIBS) -lpthread
