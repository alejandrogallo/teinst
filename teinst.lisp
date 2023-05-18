#+quicklisp (ql:quickload :cffi)
(defpackage teinst
  (:use #:cl #:cffi))
(in-package :teinst)

(ql:quickload :ale.nix)
(nix:add-to-cffi-lib "openmpi")
(mapcar #'print *foreign-library-directories*)

#|
(loop for path
        in
      '(#P"/nix/store/j9kdk5gkn30jgg5qi2k18fkf38rpzdz6-openmpi-4.1.2/lib"
        #P"../lib_shared/"
        #P"/nix/store/ysqbqgn6cylzfy9172jv28hhy1zgxriw-libfabric-1.14.0/lib"
        #P"/nix/store/fv823pky58m5drs5n66vyjbb2rhjz29k-pmix-3.2.3/lib"
        #P"/nix/store/zkiacrfnsnglrspxfw5544lpr61zanma-libpsm2-11.2.203/lib")
      do (pushnew path *foreign-library-directories*))

(mapcar #'print *foreign-library-directories*)

(print '+=========)

(define-foreign-library libmpi (t (:default "libmpi")))
(use-foreign-library libmpi)

(defcfun ("MPI_Finalize" mpi-finalize) :void)
(defcfun ("MPI_Init" mpi-init) :void)
(mpi-init)


;; (define-foreign-library libstdc++ (t (:default "libstdc++")))
;; (use-foreign-library libstdc++)

;; ctf
(define-foreign-library libctf (t (:default "libctf")))
(use-foreign-library libctf)

(defcfun ("strlen" printf) :int (what :string))

(defctype d-tensor (:pointer :char))
(defcfun ("make_tensor" make-tensor) (:pointer d-tensor)
  (order :size) (lens (:pointer :size)) (syms (:pointer :size)))

(defun make-carray (type &key initial-element (count 1))
  (foreign-alloc type :count count :initial-element initial-element))

(let ((lens (make-carray :size :count 2 :initial-element 20))
      (syms (make-carray :size :count 2 :initial-element 0)))
  (make-tensor 2 lens syms))

|#

(define-foreign-library libmpi (t (:default "libmpi")))
(use-foreign-library libmpi)
(defcfun ("MPI_Finalize" %mpi-finalize) :void)
(defcfun ("MPI_Init" %mpi-init) :void (argc (:pointer :int)) (argv (:pointer (:pointer (:pointer :char)))))

(defun mpi-init ()
  (%mpi-init (null-pointer)
             (null-pointer)))

(define-foreign-library libteinst (t (:default "libteinst")))
(use-foreign-library libteinst)

(defctype tensor-h (:pointer :size))
(defcfun ("tensor_init_s" %init-tensor-s)
    :void
  (tsr (:pointer tensor-h))
  (ndim :size)
  (lengths (:pointer :size)))

(defcfun ("tensor_init_d" %init-tensor-d)
    :void
  (tsr (:pointer tensor-h))
  (ndim :size)
  (lengths (:pointer :size)))

(defun init-tensor (type &key (lens #()))
  (check-type lens simple-array)
  (let ((size-t-size (cffi:foreign-type-size :size)))
    (with-foreign-pointer (tsr size-t-size)
      (with-foreign-array (%lens lens `(:array :size ,(length lens)))
        (ecase type
          ('float (%init-tensor-s tsr (length lens) %lens))
          ('double-float (%init-tensor-d tsr (length lens) %lens)))
        tsr))))


;; (let ((lens '(1 2 3 4 5)))
;;   (with-foreign-pointer (tsr (* (length lens) 8))
;;     (foreign- tsr)))


(let ((a (make-array 50
                     :element-type 'integer
                     :initial-element 1)))
  (with-foreign-array (s a `(:array :int32 ,(length a)))
    (loop :for i :from 0 :below (length a)
          :collect (foreign-aref s '(:array :int 1) i))))
