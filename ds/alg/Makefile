include ../../global.mk

SRCS = $(wildcard *.cc)
BUILD = $(patsubst %.cc, %.o, $(SRCS))

LIB_NAME=libbossalg.so

all:$(LIB_NAME) 
OBJS=$(BUILD)

$(LIB_NAME):$(OBJS)
	$(CC) -shared -o $@ $(OBJS)
	@if [ ! -d ../../lib/ ];then mkdir ../../lib/;fi
	mv -f $@ ../../lib/
	@echo "### $@ loaded ###\n"

.cc.o:
	$(CC) $(CC_FLAGS)   -c $<

install:
	@if [ ! -d $(BOSS_HOME)/boss/ds/alg/ ]; then mkdir -p $(BOSS_HOME)/boss/ds/alg/;fi
	cp -f *.hh $(BOSS_HOME)/boss/ds/alg/

clean:
	rm -f *.o

