include(common.m4)dnl
include(api/tensor_init.m4)dnl
include(api/tensor_free.m4)dnl
include(api/tensor_lengths.m4)dnl
dnl
dnl
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

m4_instantiate_types(`m4_tensor_lengths_implementation', ;)

m4_instantiate_types(`m4_tensor_init_implementation', ;)
m4_instantiate_types(`m4_tensor_free_implementation', ;)

void tensor_name(tensor_h t, char** nameptr) {
    const std::string name =
        (reinterpret_cast<CTF::Tensor<double> *>(t))->get_name();
    std::cout << name << std::endl;
    *nameptr = (char *)malloc(name.size());
    memcpy(*nameptr, name.c_str(), name.size());
}
}
