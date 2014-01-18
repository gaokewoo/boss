CC_FLAGS= -g
CC=g++
AR_CMD=ar -rv

#define libs path
BOSS_LIB_PATH=$(BOSS_HOME)/libs/

#define database include file path
DB_INCLUDE=$(BOSS_HOME)/db/ 


CC_INCLDIR=-I. \
		   -I$(ORACLE_HOME)/rdbms/public/ \
           -I$(BOSS_HOME)/3rd/ \
		   -I$(DB_INCLUDE) \
		   -I/usr/include

#ORALIBS=$(ORACLE_HOME)/lib -locci -lsqlplus
ORALIBS=$(ORACLE_HOME)/lib -locci -lclntsh
BOSSLIBS=$(BOSS_LIB_PATH)/ -ldb
