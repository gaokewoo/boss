include ./global.mk

define make_subdir
@for subdir in $(SUBDIRS) ; do \
    ( cd $$subdir && make $1) \
    done;
endef

BOSS_CONF=$(BOSS_HOME)/boss/conf/
BOSS_LIB=$(BOSS_HOME)/boss/lib/
BOSS_BIN=$(BOSS_HOME)/boss/bin/
BOSS_3RD=$(BOSS_HOME)/boss/3rd/

all:
	$(call make_subdir , all)

install :
	$(call make_subdir , install)

	@if [ ! -d $(BOSS_3RD) ]; then mkdir $(BOSS_3RD);fi
	cp -rf 3rd/* $(BOSS_3RD)

	@if [ ! -d $(BOSS_CONF) ]; then mkdir $(BOSS_CONF);fi
	cp -rf conf/* $(BOSS_CONF)

	@if [ ! -d $(BOSS_LIB) ]; then mkdir $(BOSS_LIB);fi
	cp -rf lib/* $(BOSS_LIB)

	@if [ ! -d $(BOSS_BIN) ]; then mkdir $(BOSS_BIN);fi
	cp -rf bin/* $(BOSS_BIN)

	cp bossstart bossstop bossstatus bossenv.sh $(BOSS_HOME)/boss/

debug:
	$(call make_subdir , debug)

clean:
	rm -rf bin/* lib/*
	$(call make_subdir , clean)

