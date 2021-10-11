#include "lite_vec.h"
#include <stdio.h>

int main(){
    lite_vec_t vec;
    lite_vec_init(&vec);

    for(int i=1; i<11; i++){
        double val = 3.14 * i;
        lite_vec_push(&vec, &val, sizeof(double));
    }

    double *vals = vec.data_ptr;
    int num_vals = vec.len / sizeof(double);
    for(int i=0; i<num_vals; i++){
        double val = vals[i];
        printf("%lf\n", val);
    }

    lite_vec_destroy(&vec);

    return 0;
}