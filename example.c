#include "lite_vec.h"
#include <stdio.h>
#include <assert.h>

int main(){
    lite_vec_t *vec = lite_vec_new();
    assert (vec);

    for(int i=1; i<11; i++){
        double val = 3.14 * i;
        assert(lite_vec_push(vec, &val, sizeof(double)) == 0);
    }

    double *vals = lite_vec_data(vec);
    int num_vals = lite_vec_len(vec) / sizeof(double);
    for(int i=0; i<num_vals; i++){
        double val = vals[i];
        printf("%lf\n", val);
    }

    lite_vec_destroy(vec);

    return 0;
}
