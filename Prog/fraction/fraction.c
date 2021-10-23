/*
 * Auteur :      Joey Martig
 * Date :        21.10.2021
 * Description : Librairie permettant le traitement de fractions
 */

#include "fraction.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Display fraction
void fraction_display(fraction frac) {
    printf("%lld / %lld\n", frac.num, frac.den);
}

// PGCD de deux nombres entiers positifs
long long fraction_pgcd(fraction frac) {
    long long t;
    while (frac.den != 0) {
        t = frac.den;
        frac.den = frac.num % frac.den;
        frac.num = t;
    }
    return frac.num;
}

// return irreductible fraction
fraction fraction_irr(fraction frac) {
    if(frac.den != 0){
        long long pgcd = llabs(fraction_pgcd(frac));
        frac.num /= pgcd;
        frac.den /= pgcd;
    }
    return frac;
}

// Retourne une fraction entière d'une fraction à une puissance entière (+ ou -)
fraction fraction_pow(fraction frac, int power) {
    frac.num = pow(frac.num, power);
    frac.den = pow(frac.den, power);
    return fraction_irr(frac);
}

// pointeurs
void fraction_add_inplace(fraction *result, fraction frac1, fraction frac2) {
    result->num = frac1.num * frac2.den + frac2.num * frac1.den;
    if (frac1.den * frac2.den == 0)
        exit(EXIT_FAILURE);
    
    result->den = frac1.den * frac2.den;
}

void fraction_sub_inplace(fraction *result, fraction frac1, fraction frac2) {
    result->num = frac1.num * frac2.den - frac2.num * frac1.den;
    if (frac1.den * frac2.den == 0)
        exit(EXIT_FAILURE);

    result->den = frac1.den * frac2.den;
}

void fraction_mul_inplace(fraction *result, fraction frac1, fraction frac2) {
    result->num = frac1.num * frac2.num;
    if (frac1.den * frac2.den == 0)
        exit(EXIT_FAILURE);

    result->den = frac1.den * frac2.den;
}

void fraction_div_inplace(fraction *result, fraction frac1, fraction frac2) {
    result->num = frac1.num * frac2.den;
    if (frac1.den * frac2.den == 0)
        exit(EXIT_FAILURE);

    result->den = frac1.den * frac2.num;
}

void fraction_neg_inplace(fraction *result, fraction frac) {
    result->num = frac.num * -1;
    result->den = frac.den;
}

// return
fraction fraction_add(fraction frac1, fraction frac2) {
    fraction result;
    result.num = frac1.num * frac2.den + frac2.num * frac1.den;
    if (frac1.den * frac2.den == 0)
        exit(EXIT_FAILURE);

    result.den = frac1.den * frac2.den;
    return fraction_irr(result);
}

fraction fraction_sub(fraction frac1, fraction frac2) {
    fraction result;
    result.num = frac1.num * frac2.den - frac2.num * frac1.den;
    if (frac1.den * frac2.den == 0)
        exit(EXIT_FAILURE);
        
    result.den = frac1.den * frac2.den;
    return fraction_irr(result);
}

fraction fraction_mul(fraction frac1, fraction frac2) {
    fraction result;
    result.num = frac1.num * frac2.num;
    if (frac1.den * frac2.den == 0)
        exit(EXIT_FAILURE);
    
    result.den = frac1.den * frac2.den;
    return fraction_irr(result);
}

fraction fraction_div(fraction frac1, fraction frac2) {
    fraction result;
    result.num = frac1.num * frac2.den;
    if (frac1.den * frac2.den == 0)
        exit(EXIT_FAILURE);
        
    result.den = frac1.den * frac2.num;
    return fraction_irr(result);
}

fraction fraction_neg(fraction frac) {
    fraction result;
    result.num = frac.num * -1;
    result.den = frac.den;
    return fraction_irr(result);
}

double fraction_to_double(fraction frac) {
    return frac.num / (double)frac.den;
}
