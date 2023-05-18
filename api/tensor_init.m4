define(
`m4_tensor_init_header',
`dnl c++
void tensor_init_$1(tensor_h* t,
                    const size_t ndim,
                    const size_t* lengths)
')

define(
`m4_tensor_init_implementation',
       `dnl c++
m4_tensor_init_header($1, $2) {
         using F = $2;
         std::vector<int64_t> syms(ndim, NS);
         *t = reinterpret_cast<tensor_h>(new CTF::Tensor<F>((int)ndim,
                                                            (int*)lengths,
                                                            (int*)syms.data()));
       }
       ')
