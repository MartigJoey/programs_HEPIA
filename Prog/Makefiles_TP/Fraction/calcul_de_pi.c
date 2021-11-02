
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