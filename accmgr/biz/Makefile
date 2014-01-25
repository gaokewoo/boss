include ${BOSS_HOME}/global.mk

.SUFFIXES:.cc

LIB_NAME=libbiz.a
all: $(LIB_NAME)
OBJS=OpenAccount.o ConfigData.o

$(LIB_NAME):$(OBJS)
	$(AR_CMD) $@ $(OBJS)
	@if [ ! -d ../libs/ ];then mkdir ../libs/;fi
	mv -f $@ $(BOSS_LIB_PATH)
	@echo "### $@ loaded ###\n"

.cc.o:
	$(CC) $(CC_FLAGS) $(CC_INCLDIR)  -c $<

clean:
	rm -f *.o
	rm -f *.lis

