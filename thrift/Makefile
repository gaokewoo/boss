include ../global.mk

SRCS = $(wildcard gen-cpp/*.cpp)
BUILD = $(patsubst %.cpp, %.o, $(SRCS))

LIB_NAME=libbossthrift.so
all: $(LIB_NAME)
OBJS=$(BUILD)


$(LIB_NAME):$(OBJS)
	$(CC) -shared -o $@ $(OBJS)
	@if [ ! -d ../lib/ ];then mkdir ../lib/;fi
	mv -f $@ ../lib/
	@echo "### $@ loaded ###\n"

.cpp.o:
	$(CC) $(CC_FLAGS) $(CC_INCLDIR)  -c $< -o $@

install:
	@if [ ! -d $(BOSS_HOME)/boss/thrift/gen-cpp ]; then mkdir -p $(BOSS_HOME)/boss/thrift/gen-cpp/;fi
	cp -f gen-cpp/*.h $(BOSS_HOME)/boss/thrift/gen-cpp/
	cp -rf gen-py $(BOSS_HOME)/boss/thrift/
	cp -f *.py $(BOSS_HOME)/boss/bin/

clean:
	rm -f gen-cpp/*.o
	rm -f gen-cpp/*.lis

