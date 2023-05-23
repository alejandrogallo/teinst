;;;; teinst.asd

(asdf:defsystem #:teinst
  :description ""
  :author "Alejandro Gallo <aamsgallo@gmail.com>"
  :license  "Specify license here"
  :version "0.0.1"
  :serial t
  :depends-on (#:cffi)
  :components ((:file "package")
               (:file "mpi")
               (:fille "cffi")
               (:file "teinst")))
