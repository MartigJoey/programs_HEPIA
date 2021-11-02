#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tableau_uni.h"

void print_horizontal_histo(int size, int array[]) {
    for (int i = 0; i < size; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < array[i]; j++)
            printf("*");
        printf("\n");
    }
}

void print_vertical_histo(int size, int array[]) {
    int max_lines = find_max(size, array);
    for (int i = max_lines; i >= 0; i--) {
        for (int j = 0; j < size; j++)
            i < array[j] ? printf("%2c ", '*') : printf("%2c ", ' ');
        printf("\n");
    }
    for (int i = 0; i < size; i++) {
        printf("%2d ", i);
    }
    printf("\n");
}