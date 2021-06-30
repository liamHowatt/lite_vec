#include "lite_vec.h"
// #include <stddef.h>
#include <stdio.h>

int main(){
    lite_vec_t vec;
    lite_vec_init(&vec, sizeof(double));

    for(int i=1; i<11; i++){
        double val = 3.14 * i;
        lite_vec_push(&vec, &val);
    }

    for(int i=0; i<10; i++){
        double val = *((double *) lite_vec_get(&vec, i));
        printf("%lf\n", val);
    }

    lite_vec_destroy(&vec);

    return 0;
}