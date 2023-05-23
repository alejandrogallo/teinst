void tensor_free_@FIELD_NAME@(tensor_h t) {
  using F = @FIELD_TYPE@;
  delete reinterpret_cast<CTF::Tensor<F> *>(t);
 }
