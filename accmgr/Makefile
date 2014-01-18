include ${BOSS_HOME}/global.mk

.SUFFIXES:.cc

all:test
test:test.cc Name.cc
	$(CC) $(CC_FLAGS) -o test test.cc Name.cc 3rd/log4z/log4z.cpp $(CC_INCLDIR) -L$(BOSSLIBS) -L$(ORALIBS)

clean:
	rm -rf test
