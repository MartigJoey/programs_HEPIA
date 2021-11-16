#include <stdio.h>

long long main(){
    long long nb1 = 36, nb2 = 90;
    printf("Valeur nb1 et nb2:");
    scanf("%lld %lld", &nb1, &nb2);

    long long copy_nb1 = nb1, copy_nb2 = nb2;

    long long t;
    while (copy_nb2 != 0){
       t = copy_nb2; 
       copy_nb2 = copy_nb1 % copy_nb2; 
       copy_nb1 = t;
    }
    
    printf("PGDC(%lld, %lld) = %lld\n", nb1, nb2, copy_nb1);
    return 0;
}