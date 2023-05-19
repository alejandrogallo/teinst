

#pragma once
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef size_t tensor_h;

void global_world_init();
void global_world_free();

/*
 * Get lengths of the tensor
 */

void tensor_lengths_s(const tensor_h t, size_t **lengths);
void tensor_lengths_d(const tensor_h t, size_t **lengths);
void tensor_lengths_c(const tensor_h t, size_t **lengths);
void tensor_lengths_z(const tensor_h t, size_t **lengths);

/*
 * Initialize Tensor
 */

void tensor_init_s(tensor_h *t, const size_t ndim, const size_t *lengths);
void tensor_init_d(tensor_h *t, const size_t ndim, const size_t *lengths);
void tensor_init_c(tensor_h *t, const size_t ndim, const size_t *lengths);
void tensor_init_z(tensor_h *t, const size_t ndim, const size_t *lengths);

/*
 * Free tensor
 */

void tensor_free_s(tensor_h t);
void tensor_free_d(tensor_h t);
void tensor_free_c(tensor_h t);
void tensor_free_z(tensor_h t);

void tensor_name(tensor_h, char **name);

#ifdef __cplusplus
}
#endif
