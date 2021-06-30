#ifndef LITE_VEC_H
#define LITE_VEC_H

#include <stddef.h>

typedef struct lite_vec_t{
    size_t len;
    size_t capacity;
    size_t dtype_size;
    void *data_ptr;
} lite_vec_t;

int lite_vec_init(lite_vec_t *obj, size_t dtype_size);
int lite_vec_push(lite_vec_t *obj, void *val_ptr);
void *lite_vec_get(lite_vec_t *obj, size_t idx);
void lite_vec_destroy(lite_vec_t *obj);

#endif