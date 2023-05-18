define(
`m4_tensor_free_header',
`dnl c++
void tensor_free_$1(tensor_h t)
')

define(
`m4_tensor_free_implementation',
       `dnl c++
m4_tensor_free_header($1, $2) {
         using F = $2;
         delete reinterpret_cast<CTF::Tensor<F> *>(t);
       }
       ')
