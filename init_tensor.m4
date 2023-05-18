define(
`m4_init_tensor_header',
`dnl c++
void init_tensor_$1(tensor_t* t,
                    const size_t ndim,
                    const size_t* lengths)
')

define(
`m4_init_tensor_implementation',
       `dnl c++
m4_init_tensor_header($1, $2) {
         using F = $2;
         std::vector<int64_t> syms(ndim, NS);
         t = reinterpret_cast<tensor_t*>(new CTF::Tensor<F>((int)ndim,
                                                            (int*)lengths,
                                                            (int*)syms.data()));
       }
       ')
