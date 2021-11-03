#include <stdio.h>

int pgcd(int val1, int val2){
    return val2 <= 0 ? val1 : pgcd(val2, val1 % val2);
}

int fibonnaci(int n, int t){
    printf("%d %d \n", n, t);
    return n < 144 ? fibonnaci(n+t, n) : n;
}

int main(){
    int nb1 = 42, nb2 = 27;
    //printf("Valeur nb1 et nb2:");
    //scanf("%d %d", &nb1, &nb2);

    int pgcd_val = pgcd(nb1, nb2);
    
    int fibonnaci_val = fibonnaci(1, 0);
    for (int n = 1, last_n = 1, t = 0; 144 >= n; n += last_n){
        //printf("%d %d\n", n, last_n);
        last_n = t;
        t = n;
    }
    

    printf("PGDC(%d, %d) = %d\n", nb1, nb2, pgcd_val);
    printf("Fibonnaci résultat = %d\n", fibonnaci_val);
    return 0;
}