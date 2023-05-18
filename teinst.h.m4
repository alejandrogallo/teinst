include(common.m4)dnl
include(api/tensor_init.m4)dnl
include(api/tensor_free.m4)dnl
dnl
dnl
#pragma once
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

  typedef size_t tensor_h;

/*
 * Initialize Tensor
 */
  m4_instantiate_types(`m4_tensor_init_header', ;)


/*
 * Free tensor
 */
  m4_instantiate_types(`m4_tensor_free_header', ;)

  void tensor_name(tensor_h, char** name);

#ifdef __cplusplus
}
#endif
