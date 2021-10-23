#include <stdio.h>

int main(){
    int value = 4;
    int fact = 1;
    for(int i = 2; i<=value; i++){
        fact *= i;
    }
    printf("%d", fact);
    return 0;
}

