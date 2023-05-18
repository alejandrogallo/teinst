CTF_PATH= ../software/atrip/build/extern/ctf/
M4_SOURCES = $(shell find . -name '*m4')
CXXFLAGS = -pedantic -Wall -Wextra -g -fmax-errors=1
CXX = mpic++ $(CXXFLAGS)

.PHONY: all m4
all: libteinst.so

m4: teinst.cxx teinst.h

teinst.cxx: $(M4_SOURCES)
teinst.h: $(M4_SOURCES)
	m4 $@.m4 > $@
	clang-format -i $@

%: %.m4
	m4 $< > $@
	clang-format -i $@

teinst.o: teinst.cxx teinst.h
	$(CXX) -fPIC -c -I. -I$(CTF_PATH)/include teinst.cxx

libteinst.so: teinst.o
	$(CXX) -fPIC -shared -fopenmp -o $@ $< $(CTF_PATH)/lib/libctf.a -lopenblas -lscalapack

clean:
	-rm *o
	-rm teinst.h teinst.cxx
