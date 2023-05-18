include(common.m4)dnl
include(api/init_tensor.m4)dnl
dnl
dnl
#include <backend/ctf.hpp>
#include <complex>
#include <iostream>
#include <string>
#include <teinst.h>

    extern "C" {

m4_instantiate_types(`m4_init_tensor_implementation', ;)

void tensor_name(tensor_h t, char** nameptr) {
    const std::string name =
        (reinterpret_cast<CTF::Tensor<double> *>(t))->get_name();
    std::cout << name << std::endl;
    *nameptr = (char *)malloc(name.size());
    memcpy(*nameptr, name.c_str(), name.size());
}
}
