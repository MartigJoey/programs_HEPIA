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

#include "tableau_uni.h"

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