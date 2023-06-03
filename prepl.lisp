(defpackage #:prepl
  (:use :cl :cl-mpi)
  (:export #:main
           #:kformat
           #:quit))
(in-package #:repl)

(defvar *prompt-symbol* "* ")

(defun main (&optional args)
  (declare (ignorable args))
  (mpi:mpi-init)

  (kformat t "Starting prepl repl~%")

  (let* ((rank (mpi-comm-rank))
         (np (mpi-comm-size))
         (object (if (= rank 0)
                     "helo"
                     nil)))
    (setq object
          (mpi-extensions:mpi-broadcast-anything 0 :object object))
    (format t "rank ~a/~a I got ~a~%" rank np object)
    (mpi-barrier)

    (let (expr)
      (loop
        (mpi-barrier)
        (finish-output)
        (when (= rank 0)
          (format t "~&~a" *prompt-symbol*)
          (finish-output)
          (setq expr (read)))
        (mpi-barrier)
        (setq expr (mpi-extensions:mpi-broadcast-anything 0 :object expr))
        (mpi-barrier)
        (let (val)
          (setq val
                (handler-case (eval expr)
                  (error (e) (progn
                               (format t "there was a problem ~a~%" e)
                               :invalid))))
          (mpi-barrier)
          (when (= rank 0)
            (format t "~a" val)
            (finish-output))
          (mpi-barrier))

        #+nil
        (let (val)
          (if (> rank 0)
              (handler-case #1=(setq val (eval expr))
                            (t nil))
              #1#)
          (format t "~&expr is ~a ⇒ ~a~%" expr val)))

      (finish-output)
      (mpi-barrier)))

  (mpi-finalize))


(defun repl ()
    (loop for expr = (read)
          if (or (eq expr :exit)
                 (equal expr '(quit)))
            return 42
          else
            do (format t "gave ~a" expr)))


(defun quit ()
  (mpi-barrier)
  (kformat t "Quitting~%")
  (mpi-finalize)
  (uiop:quit))

(defun kformat (s fmt &rest args)
  (format s "~&~a: " (mpi-comm-rank))
  (apply #'format (cons s (cons fmt args)))
  (finish-output))


(defmacro with-all (&rest body)
  )


