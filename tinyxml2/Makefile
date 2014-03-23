include ../global.mk

SRCS = $(wildcard *.cpp)
BUILD = $(patsubst %.cpp, %.o, $(SRCS))

LIB_NAME=libtinyxml2.so

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
	@if [ ! -d $(BOSS_HOME)/boss/tinyxml2/ ]; then mkdir $(BOSS_HOME)/boss/tinyxml2/;fi
	cp -f *.h $(BOSS_HOME)/boss/tinyxml2/

clean:
	rm -f *.o
	rm -f *.lis

