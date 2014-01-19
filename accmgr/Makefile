include ${BOSS_HOME}/global.mk

SUBDIRS=db pub biz

define make_subdir
@for subdir in $(SUBDIRS) ; do \
    ( cd $$subdir && make $1) \
    done;
endef

all:
	$(call make_subdir , all)

install :
	$(call make_subdir , install)

debug:
	$(call make_subdir , debug)

clean:
	$(call make_subdir , clean)

