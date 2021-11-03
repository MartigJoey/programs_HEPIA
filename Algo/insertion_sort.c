#include <stdio.h>

#define ARRAY_SIZE 8

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

int main(){
    int array[] = {0, 5, 2, 50, 20, 15, 25, 42};

    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%d\n", array[i]);
    
    return 0;
}