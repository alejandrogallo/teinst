(defcfun ("tensor_lengths_@FIELD_NAME@" %tensor-lengths-@FIELD_NAME@) :void
  (tsr tensor-h)
  (lengths :pointer))