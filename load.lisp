(ql:quickload :ale.nix)
(nix:add-to-cffi-lib "openmpi")
(mapcar #'print cffi:*foreign-library-directories*)


(ql:quickload :teinst)
(in-package :teinst)
;; (init)
