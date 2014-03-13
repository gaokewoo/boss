include ../global.mk

SRCS = $(wildcard *.cc)
BUILD = $(patsubst %.cc, %, $(SRCS))

.cc:
	$(CC) $(CC_FLAGS) -o $@ $< $(BOSS_HOME)/boss/3rd/log4z/log4z.cpp $(CC_INCLDIR) $(LIBS)
	@if [ ! -d ../bin/ ];then mkdir ../bin/;fi
	cp $@ ../bin/
	strip ../bin/$@
	@echo


all: $(BUILD)

install:

clean:
	rm -f $(BUILD)
