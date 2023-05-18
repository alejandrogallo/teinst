

#include <backend/ctf.hpp>
#include <complex>
#include <iostream>
#include <string>
#include <teinst.h>

extern "C" {

void tensor_init_s(tensor_h *t, const size_t ndim, const size_t *lengths) {
  using F = float;
  std::vector<int64_t> syms(ndim, NS);
  *t = reinterpret_cast<tensor_h>(
      new CTF::Tensor<F>((int)ndim, (int *)lengths, (int *)syms.data()));
};
void tensor_init_d(tensor_h *t, const size_t ndim, const size_t *lengths) {
  using F = double;
  std::vector<int64_t> syms(ndim, NS);
  *t = reinterpret_cast<tensor_h>(
      new CTF::Tensor<F>((int)ndim, (int *)lengths, (int *)syms.data()));
};
void tensor_init_c(tensor_h *t, const size_t ndim, const size_t *lengths) {
  using F = std::complex<float>;
  std::vector<int64_t> syms(ndim, NS);
  *t = reinterpret_cast<tensor_h>(
      new CTF::Tensor<F>((int)ndim, (int *)lengths, (int *)syms.data()));
};
void tensor_init_z(tensor_h *t, const size_t ndim, const size_t *lengths) {
  using F = std::complex<double>;
  std::vector<int64_t> syms(ndim, NS);
  *t = reinterpret_cast<tensor_h>(
      new CTF::Tensor<F>((int)ndim, (int *)lengths, (int *)syms.data()));
};

void tensor_free_s(tensor_h t) {
  using F = float;
  delete reinterpret_cast<CTF::Tensor<F> *>(t);
};
void tensor_free_d(tensor_h t) {
  using F = double;
  delete reinterpret_cast<CTF::Tensor<F> *>(t);
};
void tensor_free_c(tensor_h t) {
  using F = std::complex<float>;
  delete reinterpret_cast<CTF::Tensor<F> *>(t);
};
void tensor_free_z(tensor_h t) {
  using F = std::complex<double>;
  delete reinterpret_cast<CTF::Tensor<F> *>(t);
};

void tensor_name(tensor_h t, char **nameptr) {
  const std::string name =
      (reinterpret_cast<CTF::Tensor<double> *>(t))->get_name();
  std::cout << name << std::endl;
  *nameptr = (char *)malloc(name.size());
  memcpy(*nameptr, name.c_str(), name.size());
}
}
