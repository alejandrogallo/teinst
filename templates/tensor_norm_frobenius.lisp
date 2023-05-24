(defcfun ("tensor_norm_frobenius_@FIELD_NAME@" %tensor-norm-frobenius-@FIELD_NAME@)
    :void
  (A tensor-h)
  (min :pointer)
  (max :pointer))
