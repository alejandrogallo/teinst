#!/usr/bin/env bash

tmp=$(mktemp)

cat <<LISP_MODE >${tmp}
(ql:quickload :prepl)
(prepl::main)
LISP_MODE

sbcl --load load.lisp --load ${tmp}
