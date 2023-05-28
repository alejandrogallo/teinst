(defpackage #:prepl
  (:use :cl :cl-mpi))
(in-package #:prepl)

(defun main (&optional args)
  (declare (ignorable args))
  (teinst::init)

  (let ((rank (mpi-comm-rank))
        (np (mpi-comm-size)))
    (format t "rank ~a/~a~%" rank np))

  (teinst::finalize))
