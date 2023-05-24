CTF_PATH= ../software/atrip/build/extern/ctf/
CXXFLAGS = -fopenmp -pedantic -Wall -Wextra -g -fmax-errors=1
CXX = mpic++ $(CXXFLAGS)
OPTIMIZATION ?= -O0 -g

CTF_CPATH_ARGS = -I$(CTF_PATH)/include
CTF_LIBS = $(CTF_PATH)/lib/libctf.a -lopenblas -lscalapack

.PHONY: all test
all: libteinst.so test

c-test: libteinst.so
c-test: test.c
	mpicc -O0 -g -I. $(CXXFLAGS) test.c -o c-test -L. -lteinst

test: c-test
	./c-test
	mpirun -np 4 ./c-test

teinst.cxx: teinst.h
teinst.cxx: readme.org
teinst.h: readme.org
	emacs --batch -Q readme.org --load build.el

teinst.o: teinst.cxx teinst.h
	$(CXX) $(OPTIMIZATION) -fPIC -c -I. $(CTF_CPATH_ARGS) teinst.cxx

libteinst.so: teinst.o
	$(CXX) $(OPTIMIZATION) -fPIC -shared -fopenmp -o $@ $< $(CTF_LIBS)

instantiate:
	./tools/field-instantiate.sh templates/$(TEMPLATE)

clean:
	-rm *o
	-rm teinst.h teinst.cxx
