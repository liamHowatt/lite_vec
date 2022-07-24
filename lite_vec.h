#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct lite_vec_t lite_vec_t;

lite_vec_t *lite_vec_new();
bool lite_vec_push(lite_vec_t *self, void *val_ptr, size_t n);
void *lite_vec_data(lite_vec_t *self);
size_t lite_vec_len(lite_vec_t *self);
void lite_vec_destroy(lite_vec_t *self);
