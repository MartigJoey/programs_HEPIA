/**
 * @file stack.h
 * @author Joey Martig
 * @brief Signature de la structure stack ainsi que de ses méthodes.
 * @date 23.11.2021
 */
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct _stack {
    int *data;
    int top;
    int capacity;
} stack;


void stack_init(stack *s, int size);
bool is_empty(stack s);
void push(stack *s, int val);
void pop(stack *s, int *val);
void peek(stack *s, int *val);
void stack_destroy(stack *s);

#endif