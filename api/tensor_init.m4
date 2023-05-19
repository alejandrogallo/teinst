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
         global_world_init();
         std::vector<int> syms(ndim, NS), lens(ndim);
         for (size_t i = 0; i < ndim; i++) {
           lens[i] = lengths[i];
         }
         auto _t = new CTF::Tensor<F>((int)ndim,
                                      lens.data(),
                                      syms.data(),
                                      *TEINST_GLOBAL_WORLD);
         *t = reinterpret_cast<tensor_h>(_t);
       }
       ')
