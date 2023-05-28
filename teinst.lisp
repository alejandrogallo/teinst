(in-package :teinst)

(eval-when (:compile-toplevel :load-toplevel :execute)
    (defparameter *supported-field-types*
      '(member :float :double-float :complex :double-complex)))

(defun make-tensor-handle (type &key (lengths #()))
  (check-type lengths simple-array)
  (let ((dim (length lengths))
        (tsr (foreign-alloc :pointer)))
    (with-foreign-array (%lens lengths `(:array :size ,dim))
      (ecase type
        (:float (%tensor-init-s tsr dim %lens))
        (:double-float (%tensor-init-d tsr dim %lens))
        (:complex (%tensor-init-c tsr dim %lens))
        (:double-complex (%tensor-init-z tsr dim %lens)))
      (mem-ref tsr :pointer 0))))


(defclass tensor ()
  ((lengths :type list :initarg :lengths :reader tensor-lengths)
   (handle :type (or null foreign-pointer) :initarg :handle :initform nil)
   (type :type #.*supported-field-types*
         :initarg :type
         :reader tensor-type)))


(defmethod initialize-instance :after ((tsr tensor) &rest rest)
  (declare (ignorable rest))
  (with-slots (type handle lengths) tsr
    (unless handle
      (print "Initializing tensor")
      (setf (slot-value tsr 'handle)
            (make-tensor-handle
             type
             :lengths (make-array (length lengths)
                                  :initial-contents lengths))))))

;; (reload-foreign-libraries)

(defun init ()
  (mpi:mpi-init)
  (%global-world-init)
  t)

(defun finalize ()
  (mpi:mpi-finalize))


#|
(let ((a (make-array 50
                     :element-type 'integer
                     :initial-element 1)))
  (with-foreign-array (s a `(:array :int32 ,(length a)))
    (loop :for i :from 0 :below (length a)
          :collect (foreign-aref s '(:array :int 1) i))))

|#
