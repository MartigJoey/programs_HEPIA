/*
 * Auteur : Joey Martig
 * Date : 12.10.2021
 * Description : Traiter un tableau unidimensionnel
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tableau_uni.h"

void run_hundred_times() {
    for (size_t i = 0; i < 100; i++) {
        int size = rand() % 50 + 10;
        int *tab = malloc(size * sizeof(int));
        fill_array(tab, size);

        //printf("4. ");
        random_permutation(tab, size);
        //display_array(tab, size);

        //printf("5. ");
        cycle_permutation(tab, size, 2);
        //display_array(tab, size);

        //printf("6. ");
        swap_min_with_last(tab, size);
        //display_array(tab, size);

        //printf("7. ");
        insertion_sort(tab, size);
        //display_array(tab, size);

        //printf("8.\n Donnez une valeur entre 0 et %d ", size + 1);
        int min_value = rand() % size + 1;
        //find_smaller_elements(tab, size, min_value);

        //printf("9. \n");
        //display_array(tab, size);
        int *tab_two = malloc(size * sizeof(int));
        fill_array(tab_two, size);
        random_permutation(tab_two, size);
        //display_array(tab_two, size);

        int *tab_three = malloc(size * sizeof(int));
        sum_arrays(tab, tab_two, tab_three, size);
        //display_array(tab_three, size);

        //printf("10.\n Donnez une valeur pour multiplier le tableau (!= 0)");
        int *tab_four = malloc(size * sizeof(int));
        int multiplicator = rand() % 10 + 1;
        multiplicate_arrays(tab, tab_four, size, multiplicator);
        //display_array(tab, size);
        //display_array(tab_four, size);

        //printf("11. \n");
        double *tab_five = malloc(size * sizeof(double));
        convert_to_double(tab, tab_five, size);
        //display_array_double(tab_five, size);

        free(tab);
        free(tab_two);
        free(tab_three);
        free(tab_four);
        free(tab_five);
    }
}

int main() {
    int scanf_result;
    int size;
    printf("Entrez la taille du tableau:");
    scanf_result = scanf("%d", &size);

    int *tab = malloc(size * sizeof(int));
    fill_array(tab, size);

    printf("4. ");
    random_permutation(tab, size);
    display_array(tab, size);

    printf("5. ");
    cycle_permutation(tab, size, 2);
    display_array(tab, size);

    printf("6. ");
    swap_min_with_last(tab, size);
    display_array(tab, size);

    printf("7. ");
    insertion_sort(tab, size);
    display_array(tab, size);

    printf("8.\n Donnez une valeur entre 0 et %d ", size + 1);
    int min_value = 0;
    scanf_result = scanf("%d", &min_value);
    find_smaller_elements(tab, size, min_value);

    printf("9. \n");
    display_array(tab, size);
    int *tab_two = malloc(size * sizeof(int));
    fill_array(tab_two, size);
    random_permutation(tab_two, size);
    display_array(tab_two, size);

    int *tab_three = malloc(size * sizeof(int));
    sum_arrays(tab, tab_two, tab_three, size);
    display_array(tab_three, size);

    printf("10.\n Donnez une valeur pour multiplier le tableau (!= 0)");
    int *tab_four = malloc(size * sizeof(int));
    int multiplicator = 1;
    scanf_result = scanf("%d", &multiplicator);
    multiplicate_arrays(tab, tab_four, size, multiplicator);
    display_array(tab, size);
    display_array(tab_four, size);

    printf("11. \n");
    double *tab_five = malloc(size * sizeof(double));
    convert_to_double(tab, tab_five, size);
    display_array_double(tab_five, size);

    free(tab);
    free(tab_two);
    free(tab_three);
    free(tab_four);
    free(tab_five);

    run_hundred_times();

    return 0;
}