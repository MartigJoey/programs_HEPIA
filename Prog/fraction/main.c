/*
 * Auteur :      Joey Martig
 * Date :        21.10.2021
 * Description : Calcul la valeur de pi en utilisant la librairie fraction
 */

#include <math.h>
#include <stdio.h>

#include "fraction.h"

double formula_1() {
    fraction sum = {.num = 1, .den = 1};
    fraction current;
    double computed_pi;
    int i;
    for (i = 2; i < 100; i++) {
        current.num = 1;
        current.den = pow(i, 4);
        sum = fraction_add(sum, current);
        computed_pi = pow(fraction_to_double(sum) * 90, .25);

        if(M_PI - computed_pi < 0.00019)
            break;
    }
    printf("Pi formule 1 = %f en %d itérations\n", computed_pi, i);
    return computed_pi;
}

double formula_2() {
    fraction sum = {.num = 1, .den = 1};
    fraction current;
    double computed_pi;
    int i;
    for (i = 2; i < 100; i++) {
        current.num = pow(-1, i-1);
        current.den = pow(i, 2);
        sum = fraction_add(sum, current);

        double temp_pi = sqrt(fraction_to_double(sum) * 12);
        if(temp_pi > 0)
            computed_pi = temp_pi;
        else
            break;

        if(fabs(M_PI - computed_pi) < 0.00019)
            break;
    }
    printf("Pi formule 2 = %lf en %d itérations\n", computed_pi, i);
    return computed_pi;
}

double formula_3() {
    fraction sum = {.num = 1, .den = 1};
    fraction current;
    fraction current_1;
    fraction current_2;
    double computed_pi;
    int i;
    for (i = 1; i < 100; i++) {
        current_1.num = 2 * i;
        current_1.den = 2 * i - 1;

        current_2.num = 2 * i;
        current_2.den = 2 * i + 1;

        current = fraction_mul(current_1, current_2);
        sum = fraction_mul(sum, current);

        double temp_pi = fraction_to_double(sum) * 2;
        if(temp_pi > 0)
            computed_pi = temp_pi;
        else
            break;

        if(fabs(M_PI - computed_pi) < 0.00019)
            break;
    }
    printf("Pi formule 3 = %f en %d itérations\n", computed_pi, i);
    return computed_pi;
}

int main() {
    fraction frac_test = {.num = 10, .den = 2};
    fraction_display(frac_test);

    printf("PGCD = %lld\n", fraction_pgcd(frac_test));

    fraction frac_pow = fraction_pow(frac_test, 2);
    printf("pow 2 irreductible = %lld / %lld\n", frac_pow.num, frac_pow.den);

    fraction frac_result;
    fraction frac_1 = {.num = 1, .den = 3};
    fraction frac_2 = {.num = 3, .den = 6};
    printf("frac1 %lld / %lld   frac2 %lld / %lld\n", frac_1.num, frac_1.den, frac_2.num, frac_2.den);

    fraction_add_inplace(&frac_result, frac_1, frac_2);
    printf("frac +  %lld / %lld\n", frac_result.num, frac_result.den);
    frac_result = fraction_add(frac_1, frac_2);
    printf("frac +  %lld / %lld\n", frac_result.num, frac_result.den);

    fraction_sub_inplace(&frac_result, frac_1, frac_2);
    printf("frac -  %lld / %lld\n", frac_result.num, frac_result.den);
    frac_result = fraction_sub(frac_1, frac_2);
    printf("frac -  %lld / %lld\n", frac_result.num, frac_result.den);

    fraction_mul_inplace(&frac_result, frac_1, frac_2);
    printf("frac *  %lld / %lld\n", frac_result.num, frac_result.den);
    frac_result = fraction_mul(frac_1, frac_2);
    printf("frac *  %lld / %lld\n", frac_result.num, frac_result.den);

    fraction_div_inplace(&frac_result, frac_1, frac_2);
    printf("frac /  %lld / %lld\n", frac_result.num, frac_result.den);
    frac_result = fraction_div(frac_1, frac_2);
    printf("frac /  %lld / %lld\n", frac_result.num, frac_result.den);

    fraction_neg_inplace(&frac_result, frac_1);
    printf("frac neg  %lld / %lld\n", frac_result.num, frac_result.den);
    frac_result = fraction_neg(frac_1);
    printf("frac neg  %lld / %lld\n", frac_result.num, frac_result.den);

    formula_1();
    formula_2();
    formula_3();
    printf("Valeur de Pi = %f\n", M_PI);

    return 0;
}
