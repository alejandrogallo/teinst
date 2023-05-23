void tensor_lengths_@FIELD_NAME@(const tensor_h t,
                               size_t** lengths) {
  using F = @FIELD_TYPE@;
  auto const _t = reinterpret_cast<CTF::Tensor<F>*>(t);
  size_t * _v = (size_t*)malloc(sizeof(size_t) * _t->order);
  for (size_t i = 0; i < (size_t)_t->order; i++) {
    _v[i] = reinterpret_cast<int64_t>(_t->lens[i]);
  }
  *lengths = _v;
 }
