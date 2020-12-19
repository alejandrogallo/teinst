include etc/teinst_vars.mk
include etc/ctf_vars.mk
include etc/ctf_rules.mk

examples:
	$(MAKE) -C examples

clean:
	rm -rf lib/

.PHONY: clean examples
