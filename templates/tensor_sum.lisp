(defcfun ("tensor_sum_@FIELD_NAME@" %tensor-sum-@FIELD_NAME@) :void
  (alpha :pointer)
  (A tensor-h)
  (idx_A :string)
  (beta :pointer)
  (B tensor-h)
  (idx_B :string))
