(in-package :teinst)

(defvar *tsr* nil)

(setq *tsr* (make-instance 'tensor
                           :lengths '(50 60 70 800)
                           :type :double-float))

(with-slots (handle) *tsr*
  (mem-ref (%tensor-lengths-r-s (mem-ref handle :pointer 0) 4)
           :size 0))

(with-slots (handle) *tsr*
  (mem-ref (%tensor-lengths-r-s handle 4)
           :size 0))

(with-slots (handle) *tsr*
  (mem-aref (%tensor-lengths-r-s handle 4)
           :size 3))

(with-slots (handle) *tsr*
  (convert-from-foreign (%tensor-lengths-r-s handle 4)
                        '(:array :size 4)))


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
                        (nth i lengths))))))


(with-slots (handle lengths) *tsr*
  (assert handle)
  (assert lengths)
  (assert (equal lengths '(5 6 7 8)))
  (with-foreign-pointer (lens (* 8 (length lengths)))
    (%tensor-lengths-s handle
                       (length lengths)
                       lens)
    (loop for i below 4
          collect (mem-aref lens :size i)))
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
