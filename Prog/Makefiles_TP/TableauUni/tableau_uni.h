#ifndef TABLEAU_UNI_H
#define TABLEAU_UNI_H
#define SIZE_DIVIDER 10

void fill_array(int size, int array[], int max_val);
int find_min(int size, int array[], int max_val);
void swapValues(int indexOne, int indexTwo, int array[]);
void swamp_max_with_last(int size, int array[]);
int find_occurence(int size, int array[]);
double compute_average(int size, int array[]);
double compute_variation(int size, int array[], int avg);
void sort(int size, int array[]);
int find_median(int size, int array[]);
void print_array(int size, int array[]);
bool check_random_equity(int size, int histo[]);
void print_horizontal_histo(int size, int array[]);
int find_max(int size, int array[]);
void print_vertical_histo(int size, int array[]);

#endif