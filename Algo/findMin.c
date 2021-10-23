#include <stdio.h>

int main(){
    int array[] = {5, 10, 20 , 1, 3, -851, 49, 124};
    int min = __INT_MAX__;
    for (int i = 0; i < 8; i++)
    {
        if(array[i] < min)
            min = array[i];
    }
    printf("La valeur la plus petite est %d\n", min);
    return 0;
}