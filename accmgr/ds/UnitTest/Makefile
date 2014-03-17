include ../../global.mk

SRCS = $(wildcard *.cc)
BUILD = $(patsubst %.cc, %, $(SRCS))

.cc:
	$(CC) $(CC_FLAGS) -o $@ $< -I$(DS_INCLUDE) -I$(GMOCK_INCLUDE) -I$(GTEST_INCLUDE) -L$(BOSS_LIB_PATH) -lbossalg $(BOSS_DEV_HOME)/gmock/gmock_main.a -lpthread

all: $(BUILD)

install:

clean:
	rm -f *.o $(BUILD)
