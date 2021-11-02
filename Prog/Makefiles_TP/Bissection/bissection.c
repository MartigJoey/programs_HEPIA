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

int getSign(double value){
    int result = 0;
    if (value >= 0)
        result = 1;
    
    return result;
}

double g(double x){
    return pow(x, 5) + 2*pow(x, 4) + pow(x, 3) + pow(x, 2) - 1;
}

int bissect(double a, double b, double epsilon, double *zero){
    double c;
    int iteration = 0;
    while ((b - a) > epsilon)
    {
        c = (a + b) / 2;
        if (g(a) * g(c) <= 0)
            b = c;
        else
            a = c;

        iteration++;
    }
    *zero = c;
    return iteration;
}