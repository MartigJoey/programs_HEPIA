#ifndef ARRAY_UNI
#define ARRAY_UNI

void display_array(int *tab, int size);
void display_array_double(double *tab, int size);
void fill_array(int *tab, int size);
void random_permutation(int *tab, int size);
void cycle_permutation(int *tab, int size, int permutation);
void swap_min_with_last(int *tab, int size);
void insertion_sort(int *tab, int size);
void find_smaller_elements(int *tab, int size, int min_value);
void sum_arrays(int *tab_1, int *tab_2, int *tab_result, int size);
void multiplicate_arrays(int *tab, int *tab_result, int size, int multiplicator);
void convert_to_double(int *tab, double *tab_d, int size);

#endif