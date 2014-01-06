include ${BOSS_HOME}/global.mk

.SUFFIXES:.cc

all:test
test:test.cc
	$(CC) $(CC_FLAGS) -o test test.cc $(CC_INCLDIR) -L$(BOSSLIBS) -L$(ORALIBS)

clean:
	rm -rf test
