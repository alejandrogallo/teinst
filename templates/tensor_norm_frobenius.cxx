void tensor_norm_frobenius_@FIELD_NAME@(tensor_h const A,
                                        double * norm) {
  using F = @FIELD_TYPE@;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  *norm = _A->norm2();
 }
