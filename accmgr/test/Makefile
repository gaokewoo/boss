include ${BOSS_HOME}/global.mk

SRCS = $(wildcard *.cc)
BUILD = $(patsubst %.cc, %, $(SRCS))

.cc:
	$(CC) $(CC_FLAGS) -o $@ $< $(BOSS_HOME)/3rd/log4z/log4z.cpp $(CC_INCLDIR) $(LIBS)

all: $(BUILD)

clean:
	rm -f $(BUILD)
