(in-package :teinst)

(defvar *tsr* nil)

(setq *tsr* (make-instance 'tensor
                           :lengths '(5 6 7 8)
                           :type :double-float))

(with-slots (handle lengths) *tsr*
  (assert handle)
  (assert lengths)
  (assert (equal lengths '(5 6 7 8)))
  (with-foreign-object (lens '(:array :size 4))
    (%tensor-lengths-s handle
                       (length lengths)
                       lens)
    (loop for i below 4
          do (assert (= (mem-aref lens :size i)
                        (nth i lengths)))))
  (with-foreign-pointer (name 8)
    (format t "previous memory ~a ~a~%" name (mem-aref name :pointer 0))
    (%tensor-name handle name)
    (format t "after memory ~a ~a~%" name (mem-aref name :pointer 0))
    (loop with i = -1
          with chars = nil
          for char = (mem-aref (mem-aref name :pointer 0)
                               :char (incf i))
          if (= char 0)
            return (coerce (mapcar #'code-char (reverse chars))
                           'string)
          else
            do (push char chars))))

(let ((^a (make-instance 'tensor
                         :lengths '(10 20)
                         :type :double-float))
      (^b (make-instance 'tensor
                         :lengths '(20 10)
                         :type :double-float)))
  (with-foreign-objects ((alpha :double)
                         (beta :double))
    (setf (mem-ref alpha :double) 1.0d0
          (mem-ref beta :double) 5.0d0)
    (with-slots ((%a handle)) ^a
      (%tensor-fill-random-d %a beta alpha)
      (with-foreign-object (norm :double)
        (format t "~&norm A ~a" (mem-aref norm :double))
        (%tensor-norm-frobenius-d %a norm)
        (format t "~&norm A ~a" (mem-aref norm :double)))
      (with-slots ((%b handle)) ^b
        (%tensor-sum-d alpha
                       %a
                       "ab"
                       beta
                       %b
                       "ba")))))


(with-slots ((penis handle)) *tsr*
  penis)
