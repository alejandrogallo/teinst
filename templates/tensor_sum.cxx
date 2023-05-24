void tensor_sum_@FIELD_NAME@(@FIELD_CTYPE@ const * alpha,
                             tensor_h const A,
                             char const * idx_A,
                             @FIELD_CTYPE@ const * beta,
                             tensor_h const B,
                             char const * idx_B) {
  using F = @FIELD_TYPE@;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  auto _B = reinterpret_cast<CTF::Tensor<F>*>(B);
  _B->sum(*alpha,
          *_A,
          idx_A,
          *beta,
          idx_B);
 }
