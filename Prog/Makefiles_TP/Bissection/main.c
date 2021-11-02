/*
 * Auteur :      Joey Martig
 * Date :        05.10.2021
 * Description : Calcul le zéro d'une fonction continue
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "bissection.h"

int main(){
    double a;
    double b;
    double epsilon;
    double* zero = malloc(sizeof(double));

    printf("Donnez une valeur à a: ");
    scanf("%lf", &a);

    printf("Donnez une valeur à b (b > a): ");
    scanf("%lf", &b);
    if(b < a){
        printf("Non valide (b doit être supérieur à a)\n");
        exit(0);
    }

    if(getSign(g(a)) == getSign(g(b))){
        printf("Non valide (Signe g(a) == Signe g(b))\n");
        exit(0);
    }

    printf("Donnez une valeur à epsilon (epislon > 0): ");
    scanf("%lf", &epsilon);
    if(epsilon <= 0){
        printf("Non valide (epsilon > 0)\n");
        exit(0);
    }

    int iterations = bissect(a, b, epsilon, zero);
    printf("Bissection %lf, itérations %d\n", *zero, iterations);
    free(zero);
    return 0;
}