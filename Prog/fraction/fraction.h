/*
 * Auteur :      Joey Martig
 * Date :        21.10.2021
 * Description : Librairie permettant le traitement de fractions
 */

#ifndef FRACTION_H
#define FRACTION_H
typedef struct _fraction {
    long long num, den;
} fraction;

void fraction_display(fraction frac);
long long fraction_pgcd(fraction frac);
fraction fraction_irr(fraction frac);
fraction fraction_pow(fraction frac, int power);

void fraction_add_inplace(fraction *result, fraction frac1, fraction frac2);
void fraction_sub_inplace(fraction *result, fraction frac1, fraction frac2);
void fraction_mul_inplace(fraction *result, fraction frac1, fraction frac2);
void fraction_div_inplace(fraction *result, fraction frac1, fraction frac2);
void fraction_neg_inplace(fraction *result, fraction frac);

fraction fraction_add(fraction frac1, fraction frac2);
fraction fraction_sub(fraction frac1, fraction frac2);
fraction fraction_mul(fraction frac1, fraction frac2);
fraction fraction_div(fraction frac1, fraction frac2);
fraction fraction_neg(fraction frac);
double fraction_to_double(fraction frac);

#endif