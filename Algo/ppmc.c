#include <stdio.h>
//36, 90
//36 < 90 --> 36+36
// 72 < 90 --> 72 + 36
// 108 > 90 --> 90 + 90
//...
// 144 < 180 --> 144 + 36
// 180 = 180

int main(){
    int nb1 = 36, nb2 = 90;
    printf("Valeur nb1 et nb2:");
    scanf("%d %d", &nb1, &nb2);


    int copy_nb1 = nb1, copy_nb2 = nb2;

    /*while (copy_nb1 != copy_nb2)
    {
        if(copy_nb1 < copy_nb2)
            copy_nb1 += nb1;
        else if (copy_nb1 > copy_nb2)
            copy_nb2 += nb2;
            
    }*/
    int nb3;
    int nb4;
    int ppmc = 0;
    if(nb1 < nb2){
        nb3 = nb1;
        nb4 = nb2;
    }
    else {
        nb3 = nb2;
        nb4 = nb1;
    }
       
        
    for (size_t i = 1; i < nb4; i++)
    {
        if(nb3 * i % nb4 == 0){
            ppmc = nb3 * i;
            break;
        }
    }
    
    //printf("PPMC(%d, %d) = %d\n", nb1, nb2, copy_nb1);
    printf("PPMC(%d, %d) = %d\n", nb1, nb2, ppmc);
    return 0;
}