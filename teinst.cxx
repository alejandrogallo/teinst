#include <backend/ctf.hpp>
#include <complex>
#include <iostream>
#include <string>
#include <teinst.h>
#include <complex.h>

    extern "C" {

static CTF::World *TEINST_GLOBAL_WORLD = nullptr;

void global_world_init() {
  if (TEINST_GLOBAL_WORLD == nullptr) {
    TEINST_GLOBAL_WORLD = new CTF::World();
  }
}

void global_world_free() {
  if (TEINST_GLOBAL_WORLD != nullptr) {
    delete TEINST_GLOBAL_WORLD;
    TEINST_GLOBAL_WORLD = nullptr;
  }
}

// It will initialize the tensor handle =t= with the address of
// a valid backend tensor of kind s.
// =ndim= is the number of dimensions of the tensor, e.g. =t(a,b,c)=
// has 3 dimensions.
// =lengths= is an array with the size of every dimension.
void tensor_init_s(tensor_h* t,
                    const size_t ndim,
                    const size_t* lengths) {
  using F = float;
  global_world_init();
  std::vector<int> syms(ndim, NS), lens(ndim);
  for (size_t i = 0; i < ndim; i++) {
    lens[i] = lengths[i];
  }
  auto _t = new CTF::Tensor<F>((int)ndim, lens.data(), syms.data(),
                               *TEINST_GLOBAL_WORLD);
  *t = reinterpret_cast<tensor_h>(_t);
}
// It will initialize the tensor handle =t= with the address of
// a valid backend tensor of kind d.
// =ndim= is the number of dimensions of the tensor, e.g. =t(a,b,c)=
// has 3 dimensions.
// =lengths= is an array with the size of every dimension.
void tensor_init_d(tensor_h* t,
                    const size_t ndim,
                    const size_t* lengths) {
  using F = double;
  global_world_init();
  std::vector<int> syms(ndim, NS), lens(ndim);
  for (size_t i = 0; i < ndim; i++) {
    lens[i] = lengths[i];
  }
  auto _t = new CTF::Tensor<F>((int)ndim, lens.data(), syms.data(),
                               *TEINST_GLOBAL_WORLD);
  *t = reinterpret_cast<tensor_h>(_t);
}
// It will initialize the tensor handle =t= with the address of
// a valid backend tensor of kind c.
// =ndim= is the number of dimensions of the tensor, e.g. =t(a,b,c)=
// has 3 dimensions.
// =lengths= is an array with the size of every dimension.
void tensor_init_c(tensor_h* t,
                    const size_t ndim,
                    const size_t* lengths) {
  using F = std::complex<float>;
  global_world_init();
  std::vector<int> syms(ndim, NS), lens(ndim);
  for (size_t i = 0; i < ndim; i++) {
    lens[i] = lengths[i];
  }
  auto _t = new CTF::Tensor<F>((int)ndim, lens.data(), syms.data(),
                               *TEINST_GLOBAL_WORLD);
  *t = reinterpret_cast<tensor_h>(_t);
}
// It will initialize the tensor handle =t= with the address of
// a valid backend tensor of kind z.
// =ndim= is the number of dimensions of the tensor, e.g. =t(a,b,c)=
// has 3 dimensions.
// =lengths= is an array with the size of every dimension.
void tensor_init_z(tensor_h* t,
                    const size_t ndim,
                    const size_t* lengths) {
  using F = std::complex<double>;
  global_world_init();
  std::vector<int> syms(ndim, NS), lens(ndim);
  for (size_t i = 0; i < ndim; i++) {
    lens[i] = lengths[i];
  }
  auto _t = new CTF::Tensor<F>((int)ndim, lens.data(), syms.data(),
                               *TEINST_GLOBAL_WORLD);
  *t = reinterpret_cast<tensor_h>(_t);
}

void tensor_lengths_s(const tensor_h t,
                                 size_t dimension,
                                 size_t* lengths) {
  using F = float;
  auto const _t = reinterpret_cast<CTF::Tensor<F>*>(t);
  for (size_t i = 0; i < dimension; i++) {
    lengths[i] = reinterpret_cast<int64_t>(_t->lens[i]);
  }
 }
void tensor_lengths_d(const tensor_h t,
                                 size_t dimension,
                                 size_t* lengths) {
  using F = double;
  auto const _t = reinterpret_cast<CTF::Tensor<F>*>(t);
  for (size_t i = 0; i < dimension; i++) {
    lengths[i] = reinterpret_cast<int64_t>(_t->lens[i]);
  }
 }
void tensor_lengths_c(const tensor_h t,
                                 size_t dimension,
                                 size_t* lengths) {
  using F = std::complex<float>;
  auto const _t = reinterpret_cast<CTF::Tensor<F>*>(t);
  for (size_t i = 0; i < dimension; i++) {
    lengths[i] = reinterpret_cast<int64_t>(_t->lens[i]);
  }
 }
void tensor_lengths_z(const tensor_h t,
                                 size_t dimension,
                                 size_t* lengths) {
  using F = std::complex<double>;
  auto const _t = reinterpret_cast<CTF::Tensor<F>*>(t);
  for (size_t i = 0; i < dimension; i++) {
    lengths[i] = reinterpret_cast<int64_t>(_t->lens[i]);
  }
 }

void tensor_free_s(tensor_h t) {
  using F = float;
  delete reinterpret_cast<CTF::Tensor<F> *>(t);
 }
void tensor_free_d(tensor_h t) {
  using F = double;
  delete reinterpret_cast<CTF::Tensor<F> *>(t);
 }
void tensor_free_c(tensor_h t) {
  using F = std::complex<float>;
  delete reinterpret_cast<CTF::Tensor<F> *>(t);
 }
void tensor_free_z(tensor_h t) {
  using F = std::complex<double>;
  delete reinterpret_cast<CTF::Tensor<F> *>(t);
 }

void tensor_name(tensor_h t, char** nameptr) {
    const std::string name =
        (reinterpret_cast<CTF::Tensor<double> *>(t))->get_name();
    *nameptr = (char *)malloc(name.size());
    memcpy(*nameptr, name.c_str(), name.size());
}

void tensor_fill_random_s(tensor_h const A,
                                  float const * f_min,
                                  float const * f_max) {
  using F = float;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  _A->fill_random(*f_min, *f_max);
 }
void tensor_fill_random_d(tensor_h const A,
                                  double const * f_min,
                                  double const * f_max) {
  using F = double;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  _A->fill_random(*f_min, *f_max);
 }
void tensor_fill_random_c(tensor_h const A,
                                  _Complex float const * f_min,
                                  _Complex float const * f_max) {
  using F = std::complex<float>;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  _A->fill_random(*f_min, *f_max);
 }
void tensor_fill_random_z(tensor_h const A,
                                  _Complex double const * f_min,
                                  _Complex double const * f_max) {
  using F = std::complex<double>;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  _A->fill_random(*f_min, *f_max);
 }

void tensor_norm_frobenius_s(tensor_h const A,
                                        double * norm) {
  using F = float;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  *norm = _A->norm2();
 }
void tensor_norm_frobenius_d(tensor_h const A,
                                        double * norm) {
  using F = double;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  *norm = _A->norm2();
 }
void tensor_norm_frobenius_c(tensor_h const A,
                                        double * norm) {
  using F = std::complex<float>;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  *norm = _A->norm2();
 }
void tensor_norm_frobenius_z(tensor_h const A,
                                        double * norm) {
  using F = std::complex<double>;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  *norm = _A->norm2();
 }

void tensor_contract_s(float const * alpha,
                                  tensor_h const A,
                                  char const * idx_A,
                                  tensor_h const B,
                                  char const * idx_B,
                                  float const * beta,
                                  tensor_h C,
                                  char const * idx_C) {
  using F = float;
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
void tensor_contract_d(double const * alpha,
                                  tensor_h const A,
                                  char const * idx_A,
                                  tensor_h const B,
                                  char const * idx_B,
                                  double const * beta,
                                  tensor_h C,
                                  char const * idx_C) {
  using F = double;
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
void tensor_contract_c(_Complex float const * alpha,
                                  tensor_h const A,
                                  char const * idx_A,
                                  tensor_h const B,
                                  char const * idx_B,
                                  _Complex float const * beta,
                                  tensor_h C,
                                  char const * idx_C) {
  using F = std::complex<float>;
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
void tensor_contract_z(_Complex double const * alpha,
                                  tensor_h const A,
                                  char const * idx_A,
                                  tensor_h const B,
                                  char const * idx_B,
                                  _Complex double const * beta,
                                  tensor_h C,
                                  char const * idx_C) {
  using F = std::complex<double>;
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

void tensor_sum_s(float const * alpha,
                             tensor_h const A,
                             char const * idx_A,
                             float const * beta,
                             tensor_h const B,
                             char const * idx_B) {
  using F = float;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  auto _B = reinterpret_cast<CTF::Tensor<F>*>(B);
  _B->sum(*alpha,
          *_A,
          idx_A,
          *beta,
          idx_B);
 }
void tensor_sum_d(double const * alpha,
                             tensor_h const A,
                             char const * idx_A,
                             double const * beta,
                             tensor_h const B,
                             char const * idx_B) {
  using F = double;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  auto _B = reinterpret_cast<CTF::Tensor<F>*>(B);
  _B->sum(*alpha,
          *_A,
          idx_A,
          *beta,
          idx_B);
 }
void tensor_sum_c(_Complex float const * alpha,
                             tensor_h const A,
                             char const * idx_A,
                             _Complex float const * beta,
                             tensor_h const B,
                             char const * idx_B) {
  using F = std::complex<float>;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  auto _B = reinterpret_cast<CTF::Tensor<F>*>(B);
  _B->sum(*alpha,
          *_A,
          idx_A,
          *beta,
          idx_B);
 }
void tensor_sum_z(_Complex double const * alpha,
                             tensor_h const A,
                             char const * idx_A,
                             _Complex double const * beta,
                             tensor_h const B,
                             char const * idx_B) {
  using F = std::complex<double>;
  auto _A = reinterpret_cast<CTF::Tensor<F>*>(A);
  auto _B = reinterpret_cast<CTF::Tensor<F>*>(B);
  _B->sum(*alpha,
          *_A,
          idx_A,
          *beta,
          idx_B);
 }

} // extern "C"
