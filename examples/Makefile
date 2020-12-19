include ../etc/teinst_vars.mk
include ../etc/ctf_vars.mk

CXX=mpicxx
CXXFLAGS=-I$(CTF_INCLUDE_PATH)

CTF_SOURCE_FILES = $(wildcard *_ctf.cpp)

default: cc_ctf

%: %.cpp
	$(CXX) $(CXXFLAGS) $*.cpp -o $*

