void penis_tensor_init_@FIELD_NAME@(tensor_h* t,
                    const size_t ndim,
                    const size_t* lengths) {
  using F = @FIELD_TYPE@;
  global_world_init();
  std::vector<int> syms(ndim, NS), lens(ndim);
  for (size_t i = 0; i < ndim; i++) {
    lens[i] = lengths[i];
  }
  auto _t = new CTF::Tensor<F>((int)ndim, lens.data(), syms.data(),
                               *TEINST_GLOBAL_WORLD);
  *t = reinterpret_cast<tensor_h>(_t);
}
