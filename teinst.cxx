

#include <backend/ctf.hpp>
#include <complex>
#include <iostream>
#include <string>
#include <teinst.h>

extern "C" {

void init_tensor_s(tensor_t *t, const size_t ndim, const size_t *lengths) {
  using F = float;
  std::vector<int64_t> syms(ndim, NS);
  t = reinterpret_cast<tensor_t *>(
      new CTF::Tensor<F>((int)ndim, (int *)lengths, (int *)syms.data()));
};
void init_tensor_d(tensor_t *t, const size_t ndim, const size_t *lengths) {
  using F = double;
  std::vector<int64_t> syms(ndim, NS);
  t = reinterpret_cast<tensor_t *>(
      new CTF::Tensor<F>((int)ndim, (int *)lengths, (int *)syms.data()));
};
void init_tensor_c(tensor_t *t, const size_t ndim, const size_t *lengths) {
  using F = std::complex<float>;
  std::vector<int64_t> syms(ndim, NS);
  t = reinterpret_cast<tensor_t *>(
      new CTF::Tensor<F>((int)ndim, (int *)lengths, (int *)syms.data()));
};
void init_tensor_z(tensor_t *t, const size_t ndim, const size_t *lengths) {
  using F = std::complex<double>;
  std::vector<int64_t> syms(ndim, NS);
  t = reinterpret_cast<tensor_t *>(
      new CTF::Tensor<F>((int)ndim, (int *)lengths, (int *)syms.data()));
};

void tensor_name(tensor_t *t, char **nameptr) {
  const std::string name = ((CTF::Tensor<double> *)t)->get_name();
  std::cout << name << std::endl;
  *nameptr = (char *)malloc(name.size());
  memcpy(*nameptr, name.c_str(), name.size());
}
}
