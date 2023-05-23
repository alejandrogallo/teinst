;;;; package.lisp

(defpackage teinst
  (:use #:cl #:cffi))

(ql:quickload :ale.nix)
(nix:add-to-cffi-lib "openmpi")
(mapcar #'print *foreign-library-directories*)
