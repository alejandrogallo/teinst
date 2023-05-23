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

(defcfun ("tensor_contract_s" %tensor-contract-s) :void
  (alpha :pointer)
  (A tensor-h)
  (idx_A :string)
  (B tensor-h)
  (idx_B :string)
  (beta :pointer)
  (idx_C :string)
  (C tensor-h))
(defcfun ("tensor_contract_d" %tensor-contract-d) :void
  (alpha :pointer)
  (A tensor-h)
  (idx_A :string)
  (B tensor-h)
  (idx_B :string)
  (beta :pointer)
  (idx_C :string)
  (C tensor-h))
(defcfun ("tensor_contract_c" %tensor-contract-c) :void
  (alpha :pointer)
  (A tensor-h)
  (idx_A :string)
  (B tensor-h)
  (idx_B :string)
  (beta :pointer)
  (idx_C :string)
  (C tensor-h))
(defcfun ("tensor_contract_z" %tensor-contract-z) :void
  (alpha :pointer)
  (A tensor-h)
  (idx_A :string)
  (B tensor-h)
  (idx_B :string)
  (beta :pointer)
  (idx_C :string)
  (C tensor-h))
