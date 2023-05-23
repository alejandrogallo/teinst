(in-package :teinst)

(define-foreign-library libteinst (t (:default "libteinst")))
(use-foreign-library libteinst)

(defctype tensor-h (:pointer :size))

(defcfun ("global_world_init" %global-world-init) :void)
(defcfun ("global_world_free" %global-world-free) :void)

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
(defcfun ("tensor_init_c" %tensor-init-c)
    :void
  (tsr (:pointer tensor-h))
  (ndim :size)
  (lengths (:pointer :size)))
(defcfun ("tensor_init_z" %tensor-init-z)
    :void
  (tsr (:pointer tensor-h))
  (ndim :size)
  (lengths (:pointer :size)))

(defcfun ("tensor_lengths_s" %tensor-lengths-s) :void
  (tsr tensor-h)
  (lengths :pointer))
(defcfun ("tensor_lengths_d" %tensor-lengths-d) :void
  (tsr tensor-h)
  (lengths :pointer))
(defcfun ("tensor_lengths_c" %tensor-lengths-c) :void
  (tsr tensor-h)
  (lengths :pointer))
(defcfun ("tensor_lengths_z" %tensor-lengths-z) :void
  (tsr tensor-h)
  (lengths :pointer))

(defcfun ("tensor_free_s" %tensor-free-s) :void
  (tsr tensor-h))
(defcfun ("tensor_free_d" %tensor-free-d) :void
  (tsr tensor-h))
(defcfun ("tensor_free_c" %tensor-free-c) :void
  (tsr tensor-h))
(defcfun ("tensor_free_z" %tensor-free-z) :void
  (tsr tensor-h))
