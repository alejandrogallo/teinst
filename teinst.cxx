

#include <backend/ctf.hpp>
#include <complex>
#include <iostream>
#include <string>
#include <teinst.h>

extern "C" {

static CTF::World *TEINST_GLOBAL_WORLD = nullptr;

void global_world_init() {
  if (TEINST_GLOBAL_WORLD == nullptr) {
    TEINST_GLOBAL_WORLD = new CTF::World();
  }
}

void global_world_free() {
  std::cout << "freeing world\n";
  if (TEINST_GLOBAL_WORLD != nullptr) {
    delete TEINST_GLOBAL_WORLD;
    TEINST_GLOBAL_WORLD = nullptr;
  }
}

void tensor_lengths_s(const tensor_h t, size_t **lengths) {
  using F = float;
  auto const _t = reinterpret_cast<CTF::Tensor<F> *>(t);
  size_t *_v = (size_t *)malloc(sizeof(size_t) * _t->order);
  for (size_t i = 0; i < (size_t)_t->order; i++) {
    _v[i] = reinterpret_cast<int64_t>(_t->lens[i]);
  }
  *lengths = _v;
};
void tensor_lengths_d(const tensor_h t, size_t **lengths) {
  using F = double;
  auto const _t = reinterpret_cast<CTF::Tensor<F> *>(t);
  size_t *_v = (size_t *)malloc(sizeof(size_t) * _t->order);
  for (size_t i = 0; i < (size_t)_t->order; i++) {
    _v[i] = reinterpret_cast<int64_t>(_t->lens[i]);
  }
  *lengths = _v;
};
void tensor_lengths_c(const tensor_h t, size_t **lengths) {
  using F = std::complex<float>;
  auto const _t = reinterpret_cast<CTF::Tensor<F> *>(t);
  size_t *_v = (size_t *)malloc(sizeof(size_t) * _t->order);
  for (size_t i = 0; i < (size_t)_t->order; i++) {
    _v[i] = reinterpret_cast<int64_t>(_t->lens[i]);
  }
  *lengths = _v;
};
void tensor_lengths_z(const tensor_h t, size_t **lengths) {
  using F = std::complex<double>;
  auto const _t = reinterpret_cast<CTF::Tensor<F> *>(t);
  size_t *_v = (size_t *)malloc(sizeof(size_t) * _t->order);
  for (size_t i = 0; i < (size_t)_t->order; i++) {
    _v[i] = reinterpret_cast<int64_t>(_t->lens[i]);
  }
  *lengths = _v;
};

void tensor_init_s(tensor_h *t, const size_t ndim, const size_t *lengths) {
  using F = float;
  global_world_init();
  std::vector<int> syms(ndim, NS), lens(ndim);
  for (size_t i = 0; i < ndim; i++) {
    lens[i] = lengths[i];
  }
  auto _t = new CTF::Tensor<F>((int)ndim, lens.data(), syms.data(),
                               *TEINST_GLOBAL_WORLD);
  *t = reinterpret_cast<tensor_h>(_t);
};
void tensor_init_d(tensor_h *t, const size_t ndim, const size_t *lengths) {
  using F = double;
  global_world_init();
  std::vector<int> syms(ndim, NS), lens(ndim);
  for (size_t i = 0; i < ndim; i++) {
    lens[i] = lengths[i];
  }
  auto _t = new CTF::Tensor<F>((int)ndim, lens.data(), syms.data(),
                               *TEINST_GLOBAL_WORLD);
  *t = reinterpret_cast<tensor_h>(_t);
};
void tensor_init_c(tensor_h *t, const size_t ndim, const size_t *lengths) {
  using F = std::complex<float>;
  global_world_init();
  std::vector<int> syms(ndim, NS), lens(ndim);
  for (size_t i = 0; i < ndim; i++) {
    lens[i] = lengths[i];
  }
  auto _t = new CTF::Tensor<F>((int)ndim, lens.data(), syms.data(),
                               *TEINST_GLOBAL_WORLD);
  *t = reinterpret_cast<tensor_h>(_t);
};
void tensor_init_z(tensor_h *t, const size_t ndim, const size_t *lengths) {
  using F = std::complex<double>;
  global_world_init();
  std::vector<int> syms(ndim, NS), lens(ndim);
  for (size_t i = 0; i < ndim; i++) {
    lens[i] = lengths[i];
  }
  auto _t = new CTF::Tensor<F>((int)ndim, lens.data(), syms.data(),
                               *TEINST_GLOBAL_WORLD);
  *t = reinterpret_cast<tensor_h>(_t);
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
