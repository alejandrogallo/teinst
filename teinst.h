#ifndef _TEINST_H_DEFINED
#define _TEINST_H_DEFINED

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef size_t tensor_h;

void global_world_init();
void global_world_free();

// It will initialize the tensor handle =t= with the address of
// a valid backend tensor of kind s.
// =ndim= is the number of dimensions of the tensor, e.g. =t(a,b,c)=
// has 3 dimensions.
// =lengths= is an array with the size of every dimension.
void tensor_init_s(tensor_h* t,
                    const size_t ndim,
                    const size_t* lengths);
// It will initialize the tensor handle =t= with the address of
// a valid backend tensor of kind d.
// =ndim= is the number of dimensions of the tensor, e.g. =t(a,b,c)=
// has 3 dimensions.
// =lengths= is an array with the size of every dimension.
void tensor_init_d(tensor_h* t,
                    const size_t ndim,
                    const size_t* lengths);
// It will initialize the tensor handle =t= with the address of
// a valid backend tensor of kind c.
// =ndim= is the number of dimensions of the tensor, e.g. =t(a,b,c)=
// has 3 dimensions.
// =lengths= is an array with the size of every dimension.
void tensor_init_c(tensor_h* t,
                    const size_t ndim,
                    const size_t* lengths);
// It will initialize the tensor handle =t= with the address of
// a valid backend tensor of kind z.
// =ndim= is the number of dimensions of the tensor, e.g. =t(a,b,c)=
// has 3 dimensions.
// =lengths= is an array with the size of every dimension.
void tensor_init_z(tensor_h* t,
                    const size_t ndim,
                    const size_t* lengths);

void tensor_lengths_s(const tensor_h t,
                                 size_t dimension,
                                 size_t* lengths);
void tensor_lengths_d(const tensor_h t,
                                 size_t dimension,
                                 size_t* lengths);
void tensor_lengths_c(const tensor_h t,
                                 size_t dimension,
                                 size_t* lengths);
void tensor_lengths_z(const tensor_h t,
                                 size_t dimension,
                                 size_t* lengths);

void tensor_free_s(tensor_h t);
void tensor_free_d(tensor_h t);
void tensor_free_c(tensor_h t);
void tensor_free_z(tensor_h t);

void tensor_name(tensor_h t, char** nameptr);

void tensor_contract_s(float const * alpha,
                                  tensor_h const A,
                                  char const * idx_A,
                                  tensor_h const B,
                                  char const * idx_B,
                                  float const * beta,
                                  char const * idx_C,
                                  tensor_h C);
void tensor_contract_d(double const * alpha,
                                  tensor_h const A,
                                  char const * idx_A,
                                  tensor_h const B,
                                  char const * idx_B,
                                  double const * beta,
                                  char const * idx_C,
                                  tensor_h C);
void tensor_contract_c(_Complex float const * alpha,
                                  tensor_h const A,
                                  char const * idx_A,
                                  tensor_h const B,
                                  char const * idx_B,
                                  _Complex float const * beta,
                                  char const * idx_C,
                                  tensor_h C);
void tensor_contract_z(_Complex double const * alpha,
                                  tensor_h const A,
                                  char const * idx_A,
                                  tensor_h const B,
                                  char const * idx_B,
                                  _Complex double const * beta,
                                  char const * idx_C,
                                  tensor_h C);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _TEINST_H_DEFINED
