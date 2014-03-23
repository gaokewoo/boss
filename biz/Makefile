include ../global.mk

SRCS = $(wildcard *.cc)
BUILD = $(patsubst %.cc, %.o, $(SRCS))

LIB_NAME=libbossbiz.so

all: $(LIB_NAME)
OBJS=$(BUILD)

$(LIB_NAME):$(OBJS)
	$(CC) -shared -o $@ $(OBJS)
	@if [ ! -d ../lib/ ];then mkdir ../lib/;fi
	mv -f $@ ../lib/
	@echo "### $@ loaded ###\n"

.cc.o:
	$(CC) $(CC_FLAGS) $(CC_INCLDIR)  -c $<

install:
	@if [ ! -d $(BOSS_HOME)/boss/biz/ ]; then mkdir -p $(BOSS_HOME)/boss/biz/;fi
	cp -f *.hh $(BOSS_HOME)/boss/biz/

clean:
	rm -f *.o
	rm -f *.lis

