#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tableau_uni.h"

void swapValues(int indexOne, int indexTwo, int array[]) {
    int temp = array[indexOne];
    array[indexOne] = array[indexTwo];
    array[indexTwo] = temp;
}

void swamp_max_with_last(int size, int array[]) {
    int max = 0;
    int max_index;
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
            max_index = i;
        }
    }
    swapValues(size - 1, max_index, array);
}



void sort(int size, int array[]) {
    for (int i = size - 1; i > 1; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j + 1]) {
                swapValues(j, j + 1, array);
            }
        }
    }
}