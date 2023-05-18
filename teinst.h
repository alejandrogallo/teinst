

#pragma once
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef size_t tensor_h;

void init_tensor_s(tensor_h *t, const size_t ndim, const size_t *lengths);
void init_tensor_d(tensor_h *t, const size_t ndim, const size_t *lengths);
void init_tensor_c(tensor_h *t, const size_t ndim, const size_t *lengths);
void init_tensor_z(tensor_h *t, const size_t ndim, const size_t *lengths);

void tensor_name(tensor_h *, char **name);

#ifdef __cplusplus
}
#endif
