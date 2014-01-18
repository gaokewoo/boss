include ${BOSS_HOME}/global.mk

.SUFFIXES:.cc

all:test
test:test.cc Name.cc
	$(CC) $(CC_FLAGS) -o test test.cc Name.cc $(CC_INCLDIR) -L$(BOSSLIBS) -L$(ORALIBS)

clean:
	rm -rf test
