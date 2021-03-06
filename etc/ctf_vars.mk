# [[file:README.org::*CTF variables][CTF variables:1]]
CTF_REPOSITORY = https://github.com/cyclops-community/ctf
CTF_COMMIT    ?= v1.5.0

CTF_SRC_PATH     = $(TEINST_ROOT)/lib/src/ctf/$(CTF_COMMIT)
CTF_BUILD_PATH   = $(TEINST_ROOT)/lib/build/ctf/$(CTF_COMMIT)

CTF_CONFIG_FLAGS =

CTF_STATIC_LIB   = $(CTF_BUILD_PATH)/lib/libctf.a
CTF_INCLUDE_PATH = $(CTF_BUILD_PATH)/include
# CTF variables:1 ends here
