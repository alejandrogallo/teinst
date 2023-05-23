(in-package :teinst)

(define-foreign-library libmpi (t (:default "libmpi")))
(use-foreign-library libmpi)

(defcfun ("MPI_Finalize" %mpi-finalize) :void)
(defcfun ("MPI_Init" %mpi-init)
    :void
  (argc (:pointer :int))
  (argv (:pointer (:pointer (:pointer :char)))))

(defun mpi-init ()
  (%mpi-init (null-pointer)
             (null-pointer)))

(defcfun ("MPI_Comm_size" %mpi-comm-size) :void
  (world :int)
  (np (:pointer :int)))
