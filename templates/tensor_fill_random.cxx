void tensor_fill_random_@FIELD_NAME@(tensor_h const A,
                                  @FIELD_CTYPE@ const * f_min,
                                  @FIELD_CTYPE@ const * f_max) {
  using F = @FIELD_TYPE@;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  _A->fill_random(*f_min, *f_max);
 }
