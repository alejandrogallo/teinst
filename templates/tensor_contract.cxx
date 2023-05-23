void tensor_contract_@FIELD_NAME@(@FIELD_CTYPE@ const * alpha,
                                  tensor_h const A,
                                  char const * idx_A,
                                  tensor_h const B,
                                  char const * idx_B,
                                  @FIELD_CTYPE@ const * beta,
                                  char const * idx_C,
                                  tensor_h C) {
  using F = @FIELD_TYPE@;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  auto _B = reinterpret_cast<CTF::Tensor<F>*>(B);
  auto _C = reinterpret_cast<CTF::Tensor<F>*>(C);
  _C->contract(*alpha,
               *_A,
               idx_A,
               *_B,
               idx_B,
               *beta,
               idx_C);
 }
