(defcfun ("tensor_fill_random_@FIELD_NAME@" %tensor-fill-random-@FIELD_NAME@)
    :void
  (A tensor-h)
  (min :pointer)
  (max :pointer))
