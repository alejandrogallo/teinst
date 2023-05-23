(defcfun ("tensor_init_@FIELD_NAME@" %tensor-init-@FIELD_NAME@)
    :void
  (tsr (:pointer tensor-h))
  (ndim :size)
  (lengths (:pointer :size)))
