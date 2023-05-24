CTF_PATH= $(PWD)/vendor/ctf/
CXXFLAGS = -fopenmp -pedantic -Wall -Wextra -g -fmax-errors=1
OPTIMIZATION ?= -O0 -g

# CXX := /usr/bin/mpic++
# MPICXX := /usr/bin/mpic++
# CC := /usr/bin/mpicc
# MPICC := /usr/bin/mpicc
# AR := /usr/bin/ar
# RANLIB := /usr/bin/ranlib
# FCC := /usr/bin/gfortran-11
# MPIFCC := /usr/bin/mpif90
CC = mpicc
CXX = mpic++

SCALAPACK_PATH ?= $(PWD)/vendor/scalapack
OPENBLAS_PATH ?= $(PWD)/vendor/openblas
OPENBLAS_LD_LIBRARY_PATH ?= $(OPENBLAS_PATH)
SCALAPACK_LD_LIBRARY_PATH ?= $(SCALAPACK_PATH)/lib/

CTF_CPATH_ARGS = -I$(CTF_PATH)/include
CTF_LIBS = $(CTF_PATH)/lib/libctf.a -L$(SCALAPACK_LD_LIBRARY_PATH) -lscalapack -L$(OPENBLAS_LD_LIBRARY_PATH) -lopenblas

.PHONY: all test ctf scalapack openblas
all: libteinst.so test

c-test: libteinst.so
c-test: test.c
	mpicc -O0 -g -I. $(CXXFLAGS) test.c -o c-test -L. -lteinst $(CTF_LIBS)

test: c-test
	./c-test
	mpirun -np 4 ./c-test

teinst.cxx: teinst.h
teinst.cxx: readme.org
teinst.h: readme.org
	emacs --batch -Q readme.org --load build.el

teinst.o: teinst.cxx teinst.h
	$(CXX) $(CXXFLAGS) $(OPTIMIZATION) -fPIC -c -I. $(CTF_CPATH_ARGS) teinst.cxx

libteinst.so: teinst.o
	$(CXX) $(CXXFLAGS) $(OPTIMIZATION) -fPIC -shared -fopenmp -o $@ $< $(CTF_LIBS)

instantiate:
	./tools/field-instantiate.sh templates/$(TEMPLATE)

clean:
	-rm *o
	-rm teinst.h teinst.cxx


BLAS_PATH := /opt/OpenBLAS/lib/
ctf: $(CTF_PATH)/lib/libctf.a
$(CTF_PATH)/lib/libctf.a:
	mkdir -p $(CTF_PATH)
	-git clone git@github.com:cc4s/ctf $(CTF_PATH)
	cd $(CTF_PATH) && ./configure && \
	$(MAKE) CXX="mpic++ -std=c++11 -fopenmp -O0 -g" LIBS="-L$(BLAS_PATH) -lopenblas -L$(SCALAPACK_PATH) -lscalapack"

SCALAPACK_LIB = $(SCALAPACK_LD_LIBRARY_PATH)/libscalapack.so

scalapack: openblas
scalapack: $(SCALAPACK_LIB)

$(SCALAPACK_PATH):
	mkdir -p $(SCALAPACK_PATH)
	wget "https://github.com/Reference-ScaLAPACK/scalapack/archive/refs/tags/v2.2.0.tar.gz" -O - \
		| gunzip \
		| tar xvf - -C $(SCALAPACK_PATH) --strip-components=1

$(SCALAPACK_LIB): $(SCALAPACK_PATH)
	cd $(SCALAPACK_PATH) \
		&& \
		cmake . \
			-DBUILD_SHARED_LIBS:BOOL=ON  \
			-DCMAKE_Fortran_FLAGS:STRING="-fallow-argument-mismatch" \
			-DSCALAPACK_BUILD_TEST:BOOL=OFF  \
			-DBLAS_openblas_LIBRARY:FILEPATH=$(OPENBLAS_PATH) \
			-DBUILD_TEST:BOOL=OFF \
			-DCMAKE_C_COMPILER:FILEPATH=$(MPICC) \
			-DCMAKE_Fortran_COMPILER:FILEPATH=$(MPIFCC) \
			-DCMAKE_Fortran_COMPILER_AR:FILEPATH=$(AR) \
			-DCMAKE_Fortran_COMPILER_RANLIB:FILEPATH=$(RANLIB) \
			-DMPI_Fortran_COMPILER:FILEPATH=$(MPIFCC) \
			-DCMAKE_INSTALL_PREFIX:FILEPATH=$(SCALAPACK_PATH)/out/ \
		&& \
		$(MAKE)


OPENBLAS_LIB = $(OPENBLAS_LD_LIBRARY_PATH)/libopenblas.so.0

openblas: $(OPENBLAS_LIB)
$(OPENBLAS_PATH):
	mkdir -p $(OPENBLAS_PATH)
	wget https://github.com/xianyi/OpenBLAS/releases/download/v0.3.23/OpenBLAS-0.3.23.tar.gz -O - | gunzip | tar xvf - -C $(OPENBLAS_PATH) --strip-components=1

$(OPENBLAS_LIB): $(OPENBLAS_PATH)
	cd $(OPENBLAS_PATH) \
		&& \
		$(MAKE) CC=$(CC) FC=$(FC)
