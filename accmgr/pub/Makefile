include ${BOSS_HOME}/global.mk

SRCS = $(wildcard *.cc)
BUILD = $(patsubst %.cc, %.o, $(SRCS))

LIB_NAME=libbosspub.so

all: $(LIB_NAME)
OBJS=$(BUILD)

$(LIB_NAME):$(OBJS)
	$(CC) -shared -o $@ $(OBJS)
	@if [ ! -d ../lib/ ];then mkdir ../lib/;fi
	mv -f $@ $(BOSS_LIB_PATH)
	@echo "### $@ loaded ###\n"

.cc.o:
	$(CC) $(CC_FLAGS) $(CC_INCLDIR)  -c $<

clean:
	rm -f *.o
	rm -f *.lis

