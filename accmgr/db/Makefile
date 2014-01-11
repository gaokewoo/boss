include ${BOSS_HOME}/global.mk

.SUFFIXES:.cc


all: libdb.a
OBJS=DBInterface.o \
     OracleDB.o \
     SQLInterface.o \
     Sequence.o

libdb.a:$(OBJS)
	$(AR_CMD) $@ $(OBJS)
	if [ ! -d ../libs/ ];then mkdir ../libs/;fi
	mv -f $@ $(BOSS_LIB_PATH)
	@echo "### $@ loaded ###\n"

.cc.o:
	$(CC) $(CC_FLAGS) $(CC_INCLDIR)  -c $<

clean:
	rm -f *.o
	rm -f *.lis

