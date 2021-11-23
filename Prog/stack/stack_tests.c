/**
 * @file stack_tests.c
 * @author Joey Martig
 * @brief Test unitaires du programme stack.
 * @date 23.11.2021
 */

#include "stack.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

int main() {

    // Init
    stack s;
    int stack_size = 5;

    // Test : stack_init
    stack s0;
    stack_init(&s0, stack_size);
    assert(s0.top == -1);
    assert(s0.capacity == stack_size);
    assert(s0.data[0]);
    assert(s0.data[1]);
    assert(s0.data[2]);
    assert(s0.data[3]);
    assert(s0.data[4]);

    // Test : is_empty
    stack s1;
    stack_init(&s1, stack_size);
    assert(is_empty(s1) == true);
    push(&s1, 5);
    assert(is_empty(s1) == false);

    // Test : push
    stack s2;
    stack_init(&s2, stack_size);
    push(&s2, 5);
    assert(s2.data[s2.top] == 5);
    assert(s2.top == 0);
    push(&s2, -1);
    assert(s2.data[s2.top] == -1);
    assert(s2.top == 1);
    push(&s2, 6);
    push(&s2, 7);
    assert(s2.data[s2.top] == 7);
    assert(s2.top == 3);
    push(&s2, 2);
    push(&s2, 8);
    assert(s2.data[s2.top] == 2); // taille tableau = 5, insertion d'un sixième index = impossible
    assert(s2.top == 4);

    // Test : pop
    stack s3;
    int pop_value;
    stack_init(&s3, stack_size);
    push(&s3, 5);
    push(&s3, 4);
    push(&s3, 3);
    pop(&s3, &pop_value);
    assert(pop_value == 3);
    assert(s3.data[s3.top] == 4);
    assert(s3.top == 1);

    pop(&s3, &pop_value);
    assert(pop_value == 4);
    assert(s3.data[s3.top] == 5);
    assert(s3.top == 0);

    pop(&s3, &pop_value);
    assert(pop_value == 5);
    assert(s3.top == -1);

    // Test : peek
    stack s4;
    int peek_value;
    stack_init(&s4, stack_size);
    push(&s4, 5);
    peek(&s4, &peek_value);
    assert(peek_value == 5);
    assert(s4.top == 0);

    push(&s4, 4);
    peek(&s4, &peek_value);
    assert(peek_value == 4);
    assert(s4.top == 1);

    push(&s4, 3);
    peek(&s4, &peek_value);
    assert(peek_value == 3);
    assert(s4.top == 2);

    pop(&s4, &pop_value);
    peek(&s4, &peek_value);
    assert(peek_value == 4);
    assert(s4.data[s4.top] == 4);
    assert(s4.top == 1);

    // Test : stack_destroy
    stack s5;
    stack_init(&s5, stack_size);
    stack_destroy(&s5);
    assert(s5.data == NULL);
    assert(s5.capacity == -1);
    assert(s5.top == -1);

    stack_destroy(&s0);
    stack_destroy(&s1);
    stack_destroy(&s2);
    stack_destroy(&s3);
    stack_destroy(&s4);
    stack_destroy(&s5);

    return EXIT_SUCCESS;
}
