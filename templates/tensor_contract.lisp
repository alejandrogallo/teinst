(defcfun ("tensor_contract_@FIELD_NAME@" %tensor-contract-@FIELD_NAME@) :void
  (alpha :pointer)
  (A tensor-h)
  (idx_A :string)
  (B tensor-h)
  (idx_B :string)
  (beta :pointer)
  (idx_C :string)
  (C tensor-h))
