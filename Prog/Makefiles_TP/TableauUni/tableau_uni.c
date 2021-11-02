#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tableau_uni.h"

void fill_array(int size, int array[], int max_val) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % max_val;
    }
}

void print_array(int size, int array[]) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d,", array[i]);
    }
    printf("}\n");
}
