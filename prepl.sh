#!/usr/bin/env bash

tmp=$(mktemp)

cat <<LISP_MODE >${tmp}
(ql:quickload :prepl)
;; probably erase this from here
(ql:quickload :slynk)
(prepl::main)
LISP_MODE

export CC=/usr/bin/mpicc
export SBCL_HOME=/usr/lib/sbcl/
mpirun -np ${NP:?Number of processes NP=4 ./prepl.sh} /usr/bin/sbcl --load ${tmp}
