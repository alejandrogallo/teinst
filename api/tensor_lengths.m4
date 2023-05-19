define(
`m4_tensor_lengths_header',
`dnl c++
void tensor_lengths_$1(const tensor_h t,
                       size_t** lengths)
')

define(
`m4_tensor_lengths_implementation',
       `dnl c++
m4_tensor_lengths_header($1, $2) {
         using F = $2;
         auto const _t = reinterpret_cast<CTF::Tensor<F>*>(t);
         size_t * _v = (size_t*)malloc(sizeof(size_t) * _t->order);
         for (size_t i = 0; i < (size_t)_t->order; i++) {
           _v[i] = reinterpret_cast<int64_t>(_t->lens[i]);
         }
         *lengths = _v;
       }
       ')
