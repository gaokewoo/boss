include ${BOSS_HOME}/global.mk

SRCS = $(wildcard gen-cpp/*.cpp)
BUILD = $(patsubst %.cpp, %.o, $(SRCS))

LIB_NAME=libbossthrift.a
all: $(LIB_NAME)
OBJS=$(BUILD)


$(LIB_NAME):$(OBJS)
	echo $(OBJS)
	$(AR_CMD) $@ $(OBJS)
	@if [ ! -d ../libs/ ];then mkdir ../libs/;fi
	mv -f $@ $(BOSS_LIB_PATH)
	@echo "### $@ loaded ###\n"

.cpp.o:
	$(CC) $(CC_FLAGS) $(CC_INCLDIR)  -c $< -o $@

clean:
	rm -f gen-cpp/*.o
	rm -f gen-cpp/*.lis

