/*
 * Auteur :      Joey Martig
 * Date :        09.11.2021
 * Description : Librairie permettant le traitement de fractions
 */

#include "fraction.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Display fraction
void fraction_display(fraction *frac) {
    printf("%lld / %lld\n", frac->num, frac->den);
}

// PGCD de deux nombres entiers positifs
long long *fraction_pgcd(fraction *frac) {
    long long t;
    long long num = frac->num;
    long long den = frac->den;
    long long *result = malloc(sizeof(long long));
    while (den != 0) {
        t = den;
        den = num % den;
        num = t;
    }
    *result = num;
    return result;
}

// return irreductible fraction
fraction *fraction_irr(fraction *frac) {
    fraction *result_frac = malloc(sizeof(fraction));
    result_frac->num = frac->num;
    result_frac->den = frac->den;
    if(result_frac->den != 0){
        long long pgcd = llabs(*fraction_pgcd(result_frac));
        result_frac->num /= pgcd;
        result_frac->den /= pgcd;
    }
    return result_frac;
}

// Retourne une fraction entière d'une fraction à une puissance entière (+ ou -)
fraction *fraction_pow(fraction *frac, int power) {
    frac->num = pow(frac->num, power);
    frac->den = pow(frac->den, power);
    return fraction_irr(frac);
}

// pointeurs
void fraction_add_inplace(fraction *result, fraction *frac1, fraction *frac2) {
    result->num = frac1->num * frac2->den + frac2->num * frac1->den;
    if (frac1->den * frac2->den == 0)
        exit(EXIT_FAILURE);
    
    result->den = frac1->den * frac2->den;
}

void fraction_sub_inplace(fraction *result, fraction *frac1, fraction *frac2) {
    result->num = frac1->num * frac2->den - frac2->num * frac1->den;
    if (frac1->den * frac2->den == 0)
        exit(EXIT_FAILURE);

    result->den = frac1->den * frac2->den;
}

void fraction_mul_inplace(fraction *result, fraction *frac1, fraction *frac2) {
    result->num = frac1->num * frac2->num;
    if (frac1->den * frac2->den == 0)
        exit(EXIT_FAILURE);

    result->den = frac1->den * frac2->den;
}

void fraction_div_inplace(fraction *result, fraction *frac1, fraction *frac2) {
    result->num = frac1->num * frac2->den;
    if (frac1->den * frac2->den == 0)
        exit(EXIT_FAILURE);

    result->den = frac1->den * frac2->num;
}

void fraction_neg_inplace(fraction *result, fraction *frac) {
    result->num = frac->num * -1;
    result->den = frac->den;
}

// return
fraction *fraction_add(fraction *frac1, fraction *frac2) {
    fraction *result = malloc(sizeof(fraction));
    result->num = frac1->num * frac2->den + frac2->num * frac1->den;
    if (frac1->den * frac2->den == 0)
        exit(EXIT_FAILURE);

    result->den = frac1->den * frac2->den;
    return fraction_irr(result);
}

fraction *fraction_sub(fraction *frac1, fraction *frac2) {
    fraction *result = malloc(sizeof(fraction));
    result->num = frac1->num * frac2->den - frac2->num * frac1->den;
    if (frac1->den * frac2->den == 0)
        exit(EXIT_FAILURE);
        
    result->den = frac1->den * frac2->den;
    return fraction_irr(result);
}

fraction *fraction_mul(fraction *frac1, fraction *frac2) {
    fraction *result = malloc(sizeof(fraction));
    result->num = frac1->num * frac2->num;
    if (frac1->den * frac2->den == 0)
        exit(EXIT_FAILURE);
    
    result->den = frac1->den * frac2->den;
    return fraction_irr(result);
}

fraction *fraction_div(fraction *frac1, fraction *frac2) {
    fraction *result = malloc(sizeof(fraction));
    result->num = frac1->num * frac2->den;
    if (frac1->den * frac2->den == 0)
        exit(EXIT_FAILURE);
        
    result->den = frac1->den * frac2->num;
    return fraction_irr(result);
}

fraction *fraction_neg(fraction *frac) {
    fraction *result = malloc(sizeof(fraction));
    result->num = frac->num * -1;
    result->den = frac->den;
    return fraction_irr(result);
}

double *fraction_to_double(fraction *frac) {
    double *result = malloc(sizeof(double));
    *result = frac->num / (double)frac->den;
    return result;
}
