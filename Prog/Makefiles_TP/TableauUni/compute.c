#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tableau_uni.h"

int find_min(int size, int array[], int max_val) {
    int min = max_val;
    for (int i = 0; i < size; i++) {
        if (array[i] < min)
            min = array[i];
    }
    return min;
}


int find_occurence(int size, int array[]) {
    int element_to_find;
    printf("Donnez une valeur entre 0 et %d.\n", size / SIZE_DIVIDER);
    scanf("%d", &element_to_find);

    for (int i = 0; i < size; i++) {
        if (array[i] == element_to_find) {
            element_to_find = i;
            break;
        }
    }
    return element_to_find;
}

double compute_average(int size, int array[]) {
    double avg = 0;
    for (int i = 0; i < size; i++) {
        avg += array[i];
    }
    return avg / size;
}

double compute_variation(int size, int array[], int avg) {
    double variation = 1 / (double)size;
    double variation_array = 0;
    for (int i = 0; i < size; i++) {
        variation_array += pow(array[i] - avg, 2);
    }
    return variation * variation_array;
}

int find_median(int size, int array[]) {
    if (size % 2 == 0)
        return ((array[(size - 1) / 2] + array[size / 2]) / 2);
    else
        return array[(size - 1) / 2];
}

bool check_random_equity(int size, int histo[]) {
    int avg = compute_average(size, histo);
    if (compute_variation(size, histo, avg) == 0) {
        return true;
    }
    return false;
}

int find_max(int size, int array[]) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}