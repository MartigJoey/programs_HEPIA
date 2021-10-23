#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){
    int nb;
    scanf("%d", &nb);
    bool isPrimeNumber = true;
    // 7 % 2 == 1
    // 7 % 3 == 1
    // sqrt stop ici
    // 7 % 4 == 3
    // 7 % 5 == 2
    // 7 % 6 == 1
    for (int i = 2; i <= sqrt(nb); i++)
    {
        if(nb % i == 0){
            isPrimeNumber = false;
            break;
        }
    }

    printf("le nombre %d = %d\n", nb, isPrimeNumber);
    
    return 0;
}