include ${BOSS_HOME}/global.mk

.SUFFIXES:.cc


all: libdb.a
OBJS=DBInterface.o \
     OracleDB.o 

libdb.a:$(OBJS)
	$(AR_CMD) $@ $(OBJS)
	[ ! -f ../libs/ ] && mkdir ../libs/
	mv -f $@ $(BOSS_LIB_PATH)
	@echo "### $@ loaded ###\n"

.cc.o:
	$(CC) $(CC_FLAGS) $(CC_INCLDIR)  -c $<

clean:
	rm -f *.o
	rm -f *.lis

