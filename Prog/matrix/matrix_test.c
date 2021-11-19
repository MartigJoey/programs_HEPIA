#include "matrix.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

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
                            {0, 0}
                        };
const error_code matrix_results_0[] = {
                                ok,
                                ok,
                                ok,
                                ok,
                                err
                            };
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
        matrix_destroy(&v); // mauvaise pratique
    }

    return (test_result){.passed = passed, .name = "Test matrix_alloc"};
}

const int32_t mat_val_1[5][3] = {
                                        {3, 3, 9},
                                        {1, 1, 2},
                                        {5, 3, 15},
                                        {1, 5, 5},
                                        {1, 1, 1}
                                    };
const error_code matrix_results_1[] = {
                                ok,
                                ok,
                                ok,
                                ok,
                                err
                            };
const uint32_t nb_tests_1 = sizeof(mat_val_1) / sizeof(matrix);
test_result t_matrix_init_1() {
    bool passed = true;
    for (int i = 0; i < nb_tests_1; i++) {
        //int32_t data_mat[mat_val_1[i][m]][mat_val_1[i][n]];
        int32_t data_mat[5][5];
        data_mat[1][1] = 5;

        int32_t *data_1 = &data_mat[0][0];

        printf("%d \n", data_1[6]);

        //if(mat_val_1[i][m] > 1 && mat_val_1[i][n] > 1){
        //    data_mat[0][0] = 1;
        //    printf("data_mat %p value %d    data_2 %p value %d\n", &data_mat[0], data_mat[1][0], &*data_2, data_2[1][0]);
        //}
        //printf("m %d    n %d\n",  mat_val_1[i][m],  mat_val_1[i][n]);

        //matrix v = {.m = mat_val_1[i][m]+1, .n = mat_val_1[i][n]+1, .data = data_2};
//
        //error_code result_code = matrix_init(&v, mat_val_1[i][m], mat_val_1[i][n], mat_val_1[i][val]);
        //
        //if ((result_code != matrix_results_1[i]) || v.data[mat_val_1[i][m]][mat_val_1[i][n]] != mat_val_1[i][val]) {
        //    passed = false;
        //    break;
        //}
    }

    return (test_result){.passed = passed, .name = "Test matrix_init"};
}

// Add or remove your test function name here
const unit_test_t tests[] = {t_matrix_alloc_0, t_matrix_init_1};

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
