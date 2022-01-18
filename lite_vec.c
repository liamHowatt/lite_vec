#include "lite_vec.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void lite_vec_init(lite_vec_t *self){
    self->len = 0;
    self->capacity = 0;
    self->data_ptr = NULL;
}

int lite_vec_push(lite_vec_t *self, void *val_ptr, size_t n){
    size_t old_len = self->len;
    size_t new_len = old_len + n;
    if (new_len > self->capacity){
        size_t new_capacity = self->capacity;
        if (new_capacity == 0){
            new_capacity = 1;
        }
        while(new_capacity < new_len) {
            new_capacity *= 2;
        }
        void *new_data_pointer;
        new_data_pointer = realloc(self->data_ptr, new_capacity);
        if (!new_data_pointer) return -1;

        self->data_ptr = new_data_pointer;
        self->capacity = new_capacity;
    }
    self->len = new_len;

    memcpy(self->data_ptr + old_len, val_ptr, n);

    return 0;
}

void lite_vec_destroy(lite_vec_t *self){
    free(self->data_ptr);
}