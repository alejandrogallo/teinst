

#pragma once
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef size_t tensor_t;

void init_tensor_s(tensor_t *t, const size_t ndim, const size_t *lengths);
void init_tensor_d(tensor_t *t, const size_t ndim, const size_t *lengths);
void init_tensor_c(tensor_t *t, const size_t ndim, const size_t *lengths);
void init_tensor_z(tensor_t *t, const size_t ndim, const size_t *lengths);

void tensor_name(tensor_t *, char **name);

#ifdef __cplusplus
}
#endif
