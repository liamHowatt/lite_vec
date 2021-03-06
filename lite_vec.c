#include "lite_vec.h"
#include <string.h>
#include <stdlib.h>

typedef struct lite_vec_t{
    size_t len;
    size_t capacity;
    void *data_ptr;
} lite_vec_t;

lite_vec_t *lite_vec_new(){
    lite_vec_t *new = malloc(sizeof(lite_vec_t));
    if (!new) {
        return NULL;
    }
    new->len = 0;
    new->capacity = 0;
    new->data_ptr = NULL;
    return new;
}

bool lite_vec_push(lite_vec_t *self, void *val_ptr, size_t n){
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
        if (!new_data_pointer) return false;

        self->data_ptr = new_data_pointer;
        self->capacity = new_capacity;
    }
    self->len = new_len;

    memcpy(self->data_ptr + old_len, val_ptr, n);

    return true;
}

void *lite_vec_data(lite_vec_t *self) {
    return self->data_ptr;
}

size_t lite_vec_len(lite_vec_t *self) {
    return self->len;
}

void lite_vec_destroy(lite_vec_t *self){
    free(self->data_ptr);
    free(self);
}
