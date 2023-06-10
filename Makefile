SUBDIRS_OBJ := $(wildcard obj/toem_*)
MUX := src/mux/
KEEPALIVE := src/keepAlive/
CONFIG := src/config/

.PHONY: all clean $(SUBDIRS_OBJ) $(MUX) $(KEEPALIVE) $(CONFIG)

all: $(SUBDIRS_OBJ) $(MUX) $(KEEPALIVE) $(CONFIG)

$(SUBDIRS_OBJ):
	@$(MAKE) -s -C $@
	@echo "peripheric $@ compiled"

$(MUX):
	@$(MAKE) -s -C $@
	@echo "mux compiled"

$(KEEPALIVE):
	@$(MAKE) -s -C $@
	@echo "keepAlive compiled"

$(CONFIG):
	@$(MAKE) -s -C $@
	@echo "config compiled"

clean:
	@for dir in $(SUBDIRS_OBJ); do \
		$(MAKE) -s -C $$dir clean; \
	done
	@echo "peripheric cleaned"
	@$(MAKE) -s -C $(MUX) clean
	@echo "mux cleaned"
	@$(MAKE) -s -C $(KEEPALIVE) clean
	@echo "keepAlive cleaned"
	@$(MAKE) -s -C $(CONFIG) clean
	@echo "config cleaned"
