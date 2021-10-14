#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fill(double tab[]){
    for (int i = 0; i < SIZE; ++i) {
        tab[i] = rand() / (double)RAND_MAX;
    }
}

void sort(double tab[]){
    for (int i = 0; i < SIZE - 1; ++i) {
        double min = tab[i];
        int ind_min = i;
        for (int j = i + 1; j < SIZE; ++j) {
            if (min > tab[j]) {
                ind_min = j;
                min = tab[j];
            }
        }
        // Swap
        double tmp = tab[i];
        tab[i] = tab[ind_min];
        tab[ind_min] = tmp;
    }
}

void display(double tab[]){
    for (int i = 0; i < SIZE; ++i) {
        printf("%f ", tab[i]);
    }
    printf("\n");
}

void check(double tab[]){
    for (int i = 0; i < SIZE - 1; ++i) {
        if (tab[i] > tab[i + 1]) {
            return EXIT_FAILURE;
        }
    }
}

int main() {
    srand(time(NULL));
    double tab[SIZE];
    fill(tab);
    sort(tab);
    display(tab);
    check(tab);
    return EXIT_SUCCESS;
}
