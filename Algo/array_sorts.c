#include <stdio.h>

#define ARRAY_SIZE 8

/*
int find_min(int array[]){
    int min = array[0];
    int index = 0;
    for (int i = 0; i < ARRAY_SIZE; i++){
        if(array[i] < min){
            min = array[i];
            index = i;
        }
    }
    return index;
}

void shift(int index, int array[]){

}
*/

void swap(int *tab, int index_1, int index_2) {
    int t = tab[index_1];
    tab[index_1] = tab[index_2];
    tab[index_2] = t;
}

int partition(int *tab, int low, int high, int p){
    p--;
    high-=2;
    int i = low, j = high;

    while (i < j){
        if(tab[i] > tab[p] && tab[j] < tab[p]){
            swap(tab, i, j);
            printf("Swap: %d %d <-> %d %d\n", i, tab[i], tab[j], j);
            break;
        }

        printf("i%d j%d    tab[p] %d   p %d\n", i, j, tab[p], p);
        if(tab[i] < tab[p])
            i++;
        if(tab[j] > tab[p])
            j--;
    }
    swap(tab, j, p);
    printf("Swap: %d %d <-> %d %d\n", j, tab[j], tab[p], p);
    return j;
}

int quicksort(int *tab, int low, int high){
    int pivot_i = partition(tab, low, high, high);
    printf("pivot %d, low %d, high %d\n", pivot_i, low, high);
    if(pivot_i - low  > 2)
        quicksort(tab, low, pivot_i);
    
    if(high - pivot_i > 2)
        quicksort(tab, pivot_i+1, high);
}

int main(){
    //int array[] = {5, -2, 1, 3, 10, 15, 7, 4};
    int array[] = {0, 5, 2, 50, 20, 15, 25, 42};
    quicksort(array, 0, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%d\n", array[i]);
    
    return 0;
}