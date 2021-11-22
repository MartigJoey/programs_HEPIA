#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "matrix.h"

int main(){
    matrix *mat = (matrix*)malloc(sizeof(matrix));
    int m = 3, n = 3;
    printf("alloc\n");
    matrix_alloc(mat, m, n);
    matrix_init(mat, 2, 2, 42);
    matrix_print(*mat);

    printf("init_from_array\n");
    int32_t data[] = {43, 42, 41,
                      40, 39, 38,
                      37, 36, 35};
    matrix_init_from_array(mat, m, n, data, m*n);
    matrix_print(*mat);

    printf("mat_clone\n");
    matrix *mat_clone = (matrix*)malloc(sizeof(matrix));
    matrix_clone(mat_clone, *mat);
    matrix_print(*mat_clone);

    printf("mat_transpose\n");
    matrix *mat_transposed = (matrix*)malloc(sizeof(matrix));
    matrix_transpose(mat_transposed, *mat);
    matrix_print(*mat_transposed);

    printf("mat_sub\n");
    matrix *mat_sub = (matrix*)malloc(sizeof(matrix));
    matrix_extract_submatrix(mat_sub, *mat, 1, 3, 0, 3);
    matrix_print(*mat_sub);

    printf("bool\n");
    matrix *mat2 = (matrix*)malloc(sizeof(matrix));
    matrix_alloc(mat2, m, n);
    matrix_init(mat2, 0, 0, 42);
    bool mat_clone_is_equal = matrix_is_equal(*mat, *mat_clone);
    bool mat2_is_equal = matrix_is_equal(*mat, *mat2);
    printf("mat_clone %s\n mat2 %s\n", mat_clone_is_equal ? "true" : "false", mat2_is_equal ? "true" : "false");

    printf("get_value\n");
    int32_t *value = malloc(sizeof(int32_t));
    matrix_get(value, *mat, 0, 1);
    printf("value %d\n", *value);

    printf("set_value\n");
    matrix_set(*mat, 1, 1, 42);
    matrix_print(*mat);

    matrix_destroy(mat);
    matrix_destroy(mat_clone);
    matrix_destroy(mat_transposed);
    matrix_destroy(mat_sub);
    matrix_destroy(mat2);
    
    free(mat);
    free(mat_clone);
    free(mat_transposed);
    free(mat_sub);
    free(mat2);
    free(value);
    return 0;
}