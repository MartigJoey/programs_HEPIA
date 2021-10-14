/*
 * Auteur : Joey Martig
 * Date : 12.10.2021
 * Description : Traiter un tableau unidimensionnel
 */
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_DIVIDER 10

void fill_array(int size, int array[], int max_val) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % max_val;
    }
}

int find_min(int size, int array[], int max_val) {
    int min = max_val;
    for (int i = 0; i < size; i++) {
        if (array[i] < min)
            min = array[i];
    }
    return min;
}

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

void sort(int size, int array[]) {
    for (int i = size - 1; i > 1; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j + 1]) {
                swapValues(j, j + 1, array);
            }
        }
    }
}

int find_median(int size, int array[]) {
    if (size % 2 == 0)
        return ((array[(size - 1) / 2] + array[size / 2]) / 2);
    else
        return array[(size - 1) / 2];
}

void print_array(int size, int array[]) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d,", array[i]);
    }
    printf("}\n");
}

bool check_random_equity(int size, int histo[]) {
    int avg = compute_average(size, histo);
    if (compute_variation(size, histo, avg) == 0) {
        return true;
    }
    return false;
}

void print_horizontal_histo(int size, int array[]) {
    for (int i = 0; i < size; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < array[i]; j++)
            printf("*");
        printf("\n");
    }
}

int find_max(int size, int array[]) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
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

int main() {
    int size;
    int max_val;
    srand(time(NULL));

    printf("Donnez une valeur max.\n");
    scanf("%d", &size);
    max_val = size / SIZE_DIVIDER;

    int array[size];
    fill_array(size, array, max_val);
    print_array(size, array);
    int min = find_min(size, array, max_val);
    swamp_max_with_last(size, array);
    print_array(size, array);
    int id = find_occurence(size, array);
    double avg = compute_average(size, array);
    double variation = compute_variation(size, array, avg);
    sort(size, array);
    int median = find_median(size, array);

    int histo[max_val];
    for (int i = 0; i < max_val; i++)
        histo[i] = 0;

    for (int i = 0; i < size; i++)
        histo[array[i]]++;

    bool is_random_equal = check_random_equity(max_val, histo);
    printf("min:%d \nid:%d \navg:%lf \nvariation:%lf \nmedian:%d \nequity:%s \n",
           min, id, avg, variation, median, is_random_equal ? "yes" : "no");

    print_horizontal_histo(max_val, histo);
    print_vertical_histo(max_val, histo);

    return 0;
}