#include "matrix.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _test_result {
    bool passed;
    const char *name;
} test_result;

typedef test_result (*unit_test_t)(void);

void print_in_color(char *color, char *text) {
    printf("\033%s", color);
    printf("%s", text);
    printf("\033[0m");
}
void print_in_red(char *text) {
    print_in_color("[0;31m", text);
}
void print_in_green(char *text) {
    print_in_color("[0;32m", text);
}

bool dbl_eq(double a, double b) {
    return fabs(a - b) < 1e-6;
}

//                            m n
int m = 0, n = 1, val = 2;
const int32_t matrix_0[5][2] = {
    {3, 3},
    {1, 1},
    {5, 3},
    {1, 5},
    {0, 0}};
const error_code matrix_results_0[] = {
    ok,
    ok,
    ok,
    ok,
    err};
const uint32_t nb_tests_0 = sizeof(matrix_0) / sizeof(matrix);
test_result t_matrix_alloc_0() {
    bool passed = true;
    for (int i = 0; i < nb_tests_0; i++) {
        matrix v;
        error_code result_code = matrix_alloc(&v, matrix_0[i][m], matrix_0[i][n]);

        if ((result_code != matrix_results_0[i]) || (v.m != matrix_0[i][m] || v.n != matrix_0[i][n])) {
            passed = false;
            break;
        }
        matrix_destroy(&v);  // mauvaise pratique
    }

    return (test_result){.passed = passed, .name = "Test matrix_alloc"};
}

const int32_t mat_val_1[5][3] = {
    {3, 3, 9},
    {1, 1, 2},
    {5, 3, 15},
    {1, 5, 5},
    {1, 1, 1}};
const error_code matrix_results_1[] = {
    ok,
    ok,
    ok,
    ok,
    err};
const uint32_t nb_tests_1 = sizeof(mat_val_1) / sizeof(matrix);
test_result t_matrix_init_1() {
    bool passed = true;
    int32_t **data_mat = malloc(10 * sizeof(int32_t *));
    for (int i = 0; i < 10; i++) {
        data_mat[i] = malloc(10 * sizeof(int32_t *));
    }
    for (int i = 0; i < nb_tests_1; i++) {
        matrix v = {.m = mat_val_1[i][m], .n = mat_val_1[i][n], .data = data_mat};

        error_code result_code = matrix_init(&v, mat_val_1[i][m] - 1, mat_val_1[i][n] - 1, mat_val_1[i][val]);

        if ((result_code != matrix_results_1[i]) || v.data[mat_val_1[i][m] - 1][mat_val_1[i][n] - 1] != mat_val_1[i][val]) {
            passed = false;
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        free(data_mat[i]);
    }
    free(data_mat);

    return (test_result){.passed = passed, .name = "Test matrix_init"};
}

test_result t_matrix_init_from_array_2() {
    bool passed = true;
    int m = 3, n = 3;
    int32_t data[] = {43, 42, 41,
                      40, 39, 38,
                      37, 36, 35};

    matrix v = {.m = m, .n = n};
    matrix_alloc(&v, m, n);
    matrix_init_from_array(&v, m, n, data, m * n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v.data[i][j] != data[i * m + j])
                passed = false;
            break;
        }
    }
    matrix_destroy(&v);

    return (test_result){.passed = passed, .name = "Test matrix_init_array"};
}

test_result t_matrix_clone_3() {
    bool passed = true;
    int m = 3, n = 3;

    matrix v = {.m = m, .n = n};
    matrix_alloc(&v, m, n);
    matrix v_clone;
    matrix_clone(&v_clone, v);

    if (&(v.data) == &(v_clone.data))
        passed = false;

    matrix_destroy(&v);
    matrix_destroy(&v_clone);

    return (test_result){.passed = passed, .name = "Test matrix_clone"};
}

test_result t_matrix_transpose_4() {
    bool passed = true;
    int m = 3, n = 3;
    int32_t data[] = {43, 42, 41,
                      40, 39, 38,
                      37, 36, 35};

    int32_t result_array[3][3] = {{43, 40, 37},
                                  {42, 39, 36},
                                  {41, 38, 35}};



    matrix v = {.m = m, .n = n};
    matrix_alloc(&v, m, n);
    matrix_init_from_array(&v, m, n, data, m * n);
    matrix mat_transposed;
    matrix_transpose(&mat_transposed, v);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat_transposed.data[i][j] != result_array[i][j])
                passed = false;
        }
    }
    matrix_destroy(&v);
    matrix_destroy(&mat_transposed);

    return (test_result){.passed = passed, .name = "Test matrix_transpose"};
}

test_result t_matrix_get_5(){
    bool passed = true;
    int m = 3, n = 3;
    int result_value = 5;
    int32_t *result = malloc(sizeof(int32_t));

    matrix v = {.m = m, .n = n};
    matrix_alloc(&v, m, n);
    v.data[1][1] = result_value;
    matrix_get(result, v, 1, 1);

    printf("%d %d %d\n", *result, result_value, v.data[1][1]);

    if(*result != result_value)
        passed = false;

    matrix_destroy(&v);
    free(result);

    return (test_result){.passed = passed, .name = "Test matrix_get"};

}

test_result t_matrix_set_6(){
    bool passed = true;
    int m = 3, n = 3;
    int result = 5;

    int32_t **data_mat = malloc(m * sizeof(int32_t *));
    for (int i = 0; i < m; i++) {
        data_mat[i] = malloc(n * sizeof(int32_t *));
    }
    data_mat[1][1] = result;
    matrix v = {.m = m, .n = n, .data = data_mat};
    matrix_alloc(&v, m, n);
    matrix_set(v, 1, 1, result);

    if(v.data[1][1] != result)
        passed = false;

    for (int i = 0; i < m; i++) {
        free(data_mat[i]);
    }
    free(data_mat);
    matrix_destroy(&v);

    return (test_result){.passed = passed, .name = "Test matrix_set"};
}

// Add or remove your test function name here
const unit_test_t tests[] = {t_matrix_alloc_0, 
                             t_matrix_init_1, 
                             t_matrix_init_from_array_2, 
                             t_matrix_clone_3, 
                             t_matrix_transpose_4, 
                             t_matrix_get_5, 
                             t_matrix_set_6};

int main() {
    uint32_t nb_tests = sizeof(tests) / sizeof(unit_test_t);
    char message[256];
    bool all_passed = true;

    for (uint32_t i = 0; i < nb_tests; i++) {
        printf("Running test n°%d: ...\n", i);
        test_result r = tests[i]();
        if (r.passed) {
            sprintf(message, "\t- %s : OK", r.name);
            print_in_green(message);
        } else {
            all_passed = false;
            sprintf(message, "\t- %s : FAILED", r.name);
            print_in_red(message);
        }
        printf("\n");
    }
    if (all_passed)
        print_in_green("\nTests suite result : OK\n");
    else
        print_in_red("\nTests suite result : FAILED\n");
}
