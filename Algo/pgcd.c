#include <stdio.h>

int main(){
    int nb1 = 36, nb2 = 90;
    printf("Valeur nb1 et nb2:");
    scanf("%d %d", &nb1, &nb2);

    int copy_nb1 = nb1, copy_nb2 = nb2;

    int t;
    while (copy_nb2 != 0){
       t = copy_nb2; 
       copy_nb2 = copy_nb1 % copy_nb2; 
       copy_nb1 = t;
    }
    
    printf("PGDC(%d, %d) = %d\n", nb1, nb2, copy_nb1);
    return 0;
}