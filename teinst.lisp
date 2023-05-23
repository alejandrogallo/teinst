(in-package :teinst)

(defun tensor-init (type &key (lens #()))
  (check-type lens simple-array)
  (let ((size-t-size (cffi:foreign-type-size :size)))
    (with-foreign-pointer (tsr size-t-size)
      (with-foreign-array (%lens lens `(:array :size ,(length lens)))
        (ecase type
          (float (%tensor-init-s tsr (length lens) %lens))
          (double-float (%tensor-init-d tsr (length lens) %lens)))
        tsr))))

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
