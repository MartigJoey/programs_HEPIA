/*
 * Auteur : Joey Martig
 * Date : 13.11.2021
 * Description : Traiter un tableau unidimensionnel
 */
#include "tableau_uni.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void display_array(int *tab, int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d, ", tab[i]);
    }
    printf("}\n");
}

void display_array_double(double *tab, int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%lf, ", tab[i]);
    }
    printf("}\n");
}

void fill_array(int *tab, int size) {
    for (int i = 0; i < size; i++) {
        tab[i] = i;
    }
}

void random_permutation(int *tab, int size) {
    for (int i = 0; i < size; i++) {
        int random_index = rand() % size;  // modulo
        int t = tab[random_index];
        tab[random_index] = tab[i];
        tab[i] = t;
    }
}

void cycle_permutation(int *tab, int size, int permutation) {
    int *t_tab = malloc(size * sizeof(int));
    memcpy(t_tab, tab, size * sizeof(int));
    display_array(t_tab, size);
    for (int i = 0; i < size; i++) {
        //if(i + permutation < size)
        //    tab[i] = t_tab[i + permutation];
        //else
        //    tab[i] = t_tab[abs(size - permutation - i)];
        if (i - permutation < 0)
            tab[i] = t_tab[size - permutation + i];
        else
            tab[i] = t_tab[i - permutation];
    }
    free(t_tab);
}

int find_min_index(int *tab, int size) {
    int min = tab[0];
    int min_index = 0;
    for (int i = 0; i < size; i++) {
        if (tab[i] < min) {
            min = tab[i];
            min_index = i;
        }
    }
    return min_index;
}

void swap_two_values(int *tab, int index_1, int index_2) {
    int t = tab[index_1];
    tab[index_1] = tab[index_2];
    tab[index_2] = t;
}

void swap_min_with_last(int *tab, int size) {
    int min_index = find_min_index(tab, size);
    swap_two_values(tab, min_index, size - 1);
}

void insertion_sort(int *tab, int size) {
    int i = 1;
    while (i < size) {
        int j = i;
        while (j > 0 && tab[j - 1] > tab[j]) {
            swap_two_values(tab, j, j - 1);
            j = j - 1;
        }
        i++;
    }
}

void find_smaller_elements(int *tab, int size, int min_value){
    printf("{ ");
    for (int i = 0; i < size; i++){
        if(tab[i] < min_value)
            printf("%d, ", tab[i]);
    }
    printf(" }\n");
}

void sum_arrays(int *tab_1, int *tab_2, int *tab_result, int size){
    for (int i = 0; i < size; i++){
        tab_result[i] = tab_1[i] + tab_2[i];
    }
}

void multiplicate_arrays(int *tab, int *tab_result, int size, int multiplicator){
    for (int i = 0; i < size; i++){
        tab_result[i] = tab[i] * multiplicator;
    }
}

void convert_to_double(int *tab, double *tab_d, int size){
    for (int i = 0; i < size; i++){
        tab_d[i] = (double)tab[i];
    }
}