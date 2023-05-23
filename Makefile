CTF_PATH= ../software/atrip/build/extern/ctf/
M4_SOURCES = $(shell find . -name '*m4')
CXXFLAGS = -fopenmp -pedantic -Wall -Wextra -g -fmax-errors=1
CXX = mpic++ $(CXXFLAGS)

CTF_CPATH = -I$(CTF_PATH)/include
CTF_LIBS = $(CTF_PATH)/lib/libctf.a -lopenblas -lscalapack

.PHONY: all
all: libteinst.so test

m4: teinst.cxx teinst.h

test: test.c libteinst.so
	mpicc -I. $(CXXFLAGS) test.c -o test -L. -lteinst

# teinst.cxx: $(M4_SOURCES)
# teinst.h: $(M4_SOURCES)
# 	m4 $@.m4 > $@
# 	clang-format -i $@

teinst.cxx teinst.h: readme.org
	emacs --batch -Q readme.org --load build.el

# %: %.m4
# 	m4 $< > $@
# 	clang-format -i $@

teinst.o: teinst.cxx teinst.h
	$(CXX) -fPIC -c -I. $(CTF_CPATH) teinst.cxx

libteinst.so: teinst.o
	$(CXX) -fPIC -shared -fopenmp -o $@ $< $(CTF_LIBS)

instantiate:
	./tools/field-instantiate.sh templates/$(TEMPLATE)


clean:
	-rm *o
	-rm teinst.h teinst.cxx
