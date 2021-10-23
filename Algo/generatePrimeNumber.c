/*
 * Auteur :      Joey Martig
 * Date :        13.10.2021
 * Description : Affiche les nombres premiers jusqu'à N.
 */

#include <stdbool.h>
#include <stdio.h>

#define ARRAY_SIZE 100

void generate_array_bool(bool array[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = true;
    }
}

void is_divided_by(bool is_prime_numbers[], int multiple){
    for (int i = 0; i < ARRAY_SIZE; i++){
        if(!is_prime_numbers[i])
            continue;

        if(i % multiple == 0 && i != multiple)
            is_prime_numbers[i] = false;
    }
}

void display_prime_numbers(bool is_prime_numbers[]){
    printf("Nombre premiers jusqu'à %d:\n", ARRAY_SIZE);
    for (int i = 2; i < ARRAY_SIZE; i++){
        if(is_prime_numbers[i])
            printf("%d, ", i);
    }
    printf("\n");
}

int main() {
    bool is_prime_numbers[ARRAY_SIZE];

    generate_array_bool(is_prime_numbers);

    for (int i = 2; i < ARRAY_SIZE; i++){
        if(is_prime_numbers[i])
            is_divided_by(is_prime_numbers, i);
    }

    display_prime_numbers(is_prime_numbers);

    return 0;
}