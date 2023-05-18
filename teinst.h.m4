include(common.m4)dnl
include(api/init_tensor.m4)dnl
dnl
dnl
#pragma once
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

  typedef size_t tensor_h;

  m4_instantiate_types(`m4_init_tensor_header', ;)

  void tensor_name(tensor_h, char** name);

#ifdef __cplusplus
}
#endif
