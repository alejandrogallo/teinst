;;;; prepl.asd

(asdf:defsystem #:prepl
  :description "Parallel repl"
  :author "Alejandro Gallo <aamsgallo@gmail.com>"
  :license  "Specify license here"
  :version "0.0.1"
  :serial t

  :depends-on (#:teinst)
  :defsystem-depends-on (:cl-mpi-asdf-integration)

  :class :mpi-program
  :build-operation :static-program-op
  :build-pathname "prepl"
  :entry-point "prepl:main"
  :components ((:file "prepl")))
