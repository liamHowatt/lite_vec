#include "lite_vec.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

int lite_vec_init(lite_vec_t *obj, size_t dtype_size){
    void *data_ptr = malloc(dtype_size);
    if (!data_ptr) return -1;

    obj->len = 0;
    obj->capacity = 1;
    obj->dtype_size = dtype_size;
    obj->data_ptr = data_ptr;

    return 0;
}

int lite_vec_push(lite_vec_t *obj, void *val_ptr){
    size_t new_len = obj->len + 1;
    if (new_len > obj->capacity){
        size_t new_capacity = obj->capacity * 2;
        void *new_data_pointer = realloc(obj->data_ptr, new_capacity * obj->dtype_size);
        if (!new_data_pointer) return -1;

        obj->data_ptr = new_data_pointer;
        obj->capacity = new_capacity;
    }
    obj->len = new_len;

    memcpy(obj->data_ptr + ((obj->len - 1) * obj->dtype_size), val_ptr, obj->dtype_size);

    return 0;
}

void *lite_vec_get(lite_vec_t *obj, size_t idx){
    return obj->data_ptr + (idx * obj->dtype_size);
}

void lite_vec_destroy(lite_vec_t *obj){
    free(obj->data_ptr);
}