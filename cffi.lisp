(in-package :teinst)

(define-foreign-library libteinst (t (:default "libteinst")))
(use-foreign-library libteinst)

(defctype tensor-h (:pointer :size))

(defcfun ("global_world_init" %global-world-init) :void)
(defcfun ("global_world_free" %global-world-free) :void)

(defcfun ("tensor_init_s" %tensor-init-s) :void
  "
It will initialize the tensor handle =t= with the address of
a valid backend tensor of kind s.
=ndim= is the number of dimensions of the tensor, e.g. =t(a,b,c)=
has 3 dimensions.
=lengths= is an array with the size of every dimension."
  (tsr (:pointer tensor-h))
  (ndim :size)
  (lengths (:pointer :size)))
(defcfun ("tensor_init_d" %tensor-init-d) :void
  "
It will initialize the tensor handle =t= with the address of
a valid backend tensor of kind d.
=ndim= is the number of dimensions of the tensor, e.g. =t(a,b,c)=
has 3 dimensions.
=lengths= is an array with the size of every dimension."
  (tsr (:pointer tensor-h))
  (ndim :size)
  (lengths (:pointer :size)))
(defcfun ("tensor_init_c" %tensor-init-c) :void
  "
It will initialize the tensor handle =t= with the address of
a valid backend tensor of kind c.
=ndim= is the number of dimensions of the tensor, e.g. =t(a,b,c)=
has 3 dimensions.
=lengths= is an array with the size of every dimension."
  (tsr (:pointer tensor-h))
  (ndim :size)
  (lengths (:pointer :size)))
(defcfun ("tensor_init_z" %tensor-init-z) :void
  "
It will initialize the tensor handle =t= with the address of
a valid backend tensor of kind z.
=ndim= is the number of dimensions of the tensor, e.g. =t(a,b,c)=
has 3 dimensions.
=lengths= is an array with the size of every dimension."
  (tsr (:pointer tensor-h))
  (ndim :size)
  (lengths (:pointer :size)))

(defcfun ("tensor_lengths_r_s" %tensor-lengths-r-s)
    :pointer
  (tsr tensor-h)
  (dimension :size))
(defcfun ("tensor_lengths_r_d" %tensor-lengths-r-d)
    :pointer
  (tsr tensor-h)
  (dimension :size))
(defcfun ("tensor_lengths_r_c" %tensor-lengths-r-c)
    :pointer
  (tsr tensor-h)
  (dimension :size))
(defcfun ("tensor_lengths_r_z" %tensor-lengths-r-z)
    :pointer
  (tsr tensor-h)
  (dimension :size))

(defcfun ("tensor_lengths_s" %tensor-lengths-s) :void
  (tsr tensor-h)
  (dimension :size)
  (lengths :pointer))
(defcfun ("tensor_lengths_d" %tensor-lengths-d) :void
  (tsr tensor-h)
  (dimension :size)
  (lengths :pointer))
(defcfun ("tensor_lengths_c" %tensor-lengths-c) :void
  (tsr tensor-h)
  (dimension :size)
  (lengths :pointer))
(defcfun ("tensor_lengths_z" %tensor-lengths-z) :void
  (tsr tensor-h)
  (dimension :size)
  (lengths :pointer))

(defcfun ("tensor_free_s" %tensor-free-s) :void
  (tsr tensor-h))
(defcfun ("tensor_free_d" %tensor-free-d) :void
  (tsr tensor-h))
(defcfun ("tensor_free_c" %tensor-free-c) :void
  (tsr tensor-h))
(defcfun ("tensor_free_z" %tensor-free-z) :void
  (tsr tensor-h))

(defcfun ("tensor_name" %tensor-name) :void
  (tsr tensor-h)
  (name :pointer))
