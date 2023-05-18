include(common.m4)dnl
include(init_tensor.m4)dnl
dnl
dnl
#include <backend/ctf.hpp>
#include <teinst.h>
#include <string>
#include <complex>
#include <iostream>


extern "C" {

m4_instantiate_types(`m4_init_tensor_implementation', ;)

void tensor_name(tensor_t* t, char** nameptr) {
  const std::string name = ((CTF::Tensor<double>*)t)->get_name();
  std::cout << name << std::endl;
  *nameptr = (char*)malloc(name.size());
  memcpy(*nameptr, name.c_str(), name.size());
}

}
