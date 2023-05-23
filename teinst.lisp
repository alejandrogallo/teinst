(in-package :teinst)


(defun make-tensor-handle (type &key (lengths #()))
  (check-type lengths simple-array)
  (let ((size-t-size (cffi:foreign-type-size :size))
        (dim (length lengths)))
    (with-foreign-pointer (tsr size-t-size)
      (with-foreign-array (%lens lengths `(:array :size ,dim))
        (ecase type
          (:float (%tensor-init-s tsr dim %lens))
          (:double-float (%tensor-init-d tsr dim %lens))
          (:complex (%tensor-init-c tsr dim %lens))
          (:double-complex (%tensor-init-z tsr dim %lens)))
        tsr))))


(defclass tensor ()
  ((lengths :type list :initarg :lengths :reader tensor-lengths)
   (handle :type (or null foreign-pointer) :initarg :handle :initform nil)
   (type :type (member :float :double-float :complex :double-complex)
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
  (mpi-init)
  (%global-world-init)
  t)


#|
(let ((a (make-array 50
                     :element-type 'integer
                     :initial-element 1)))
  (with-foreign-array (s a `(:array :int32 ,(length a)))
    (loop :for i :from 0 :below (length a)
          :collect (foreign-aref s '(:array :int 1) i))))

|#
