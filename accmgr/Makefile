include ${BOSS_HOME}/global.mk

.SUFFIXES:.cc

all:test
test:test.cc
	$(CC) $(CC_FLAGS) $(CC_INCLDIR) -L$(ORALIBS) -L$(BOSSLIBS) -o test test.cc

