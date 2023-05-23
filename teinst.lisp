(in-package :teinst)

(ql:quickload :ale.nix)
(nix:add-to-cffi-lib "openmpi")
(mapcar #'print *foreign-library-directories*)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; MPI ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

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


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; TEINST ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define-foreign-library libteinst (t (:default "libteinst")))
(use-foreign-library libteinst)

(defctype tensor-h (:pointer :size))
(defcfun ("tensor_init_s" %tensor-init-s)
    :void
  (tsr (:pointer tensor-h))
  (ndim :size)
  (lengths (:pointer :size)))

(defcfun ("tensor_init_d" %tensor-init-d)
    :void
  (tsr (:pointer tensor-h))
  (ndim :size)
  (lengths (:pointer :size)))

(defcfun ("tensor_free_s" %tensor-free-s)
    :void
  (tsr tensor-h))

(defcfun ("tensor_free_d" %tensor-free-d)
    :void
  (tsr tensor-h))

(defun tensor-init (type &key (lens #()))
  (check-type lens simple-array)
  (let ((size-t-size (cffi:foreign-type-size :size)))
    (with-foreign-pointer (tsr size-t-size)
      (with-foreign-array (%lens lens `(:array :size ,(length lens)))
        (ecase type
          (float (%tensor-init-s tsr (length lens) %lens))
          (double-float (%tensor-init-d tsr (length lens) %lens)))
        tsr))))

(defcfun ("global_world_init" %global-world-init) :void)
(defcfun ("global_world_free" %global-world-free) :void)

(defcfun ("tensor_lengths_s" %tensor-lengths-s) :void
  (tsr tensor-h)
  (lengths :pointer))

(defcfun ("printf" %printf) :void (fmt :pointer))


;; (let ((lens '(1 2 3 4 5)))
;;   (with-foreign-pointer (tsr (* (length lens) 8))
;;     (foreign- tsr)))

;; (reload-foreign-libraries)

(defun init ()
  (mpi-init)
  (%global-world-init)
  t)


(let ((a (make-array 50
                     :element-type 'integer
                     :initial-element 1)))
  (with-foreign-array (s a `(:array :int32 ,(length a)))
    (loop :for i :from 0 :below (length a)
          :collect (foreign-aref s '(:array :int 1) i))))
