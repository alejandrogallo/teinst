void tensor_lengths_@FIELD_NAME@(const tensor_h t,
                                 size_t dimension,
                                 size_t* lengths) {
  using F = @FIELD_TYPE@;
  auto const _t = reinterpret_cast<CTF::Tensor<F>*>(t);
  for (size_t i = 0; i < dimension; i++) {
    lengths[i] = reinterpret_cast<int64_t>(_t->lens[i]);
  }
 }
