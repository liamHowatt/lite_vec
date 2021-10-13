#ifndef LITE_VEC_H
#define LITE_VEC_H

#include <stddef.h>

typedef struct lite_vec_t{
    size_t len;
    size_t capacity;
    void *data_ptr;
} lite_vec_t;

void lite_vec_init(lite_vec_t *self);
int lite_vec_push(lite_vec_t *self, void *val_ptr, size_t n);
void lite_vec_destroy(lite_vec_t *self);

#endif