/**
 * @file stack.c
 * @author Joey Martig
 * @brief Librairie de pile.
 * @date 23.11.2021
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"

// alloue le tableau data de taille size et initialise l’indice du sommet de la pile top.
void stack_init(stack *s, int size){
    s->data = malloc(size * sizeof(int));
    s->capacity = size;
    s->top = -1;
}

// Vérifie si la pile est vide.
bool is_empty(stack s){
    return s.top > -1 ? false : true;
}

// Empile un élément au sommet.
void push(stack *s, int val){
    if(s->top+1 < s->capacity){
        s->top++;
        s->data[s->top] = val;
    }
}

// Dépile un élément du sommet.
void pop(stack *s, int *val){
    if(s->top-1 >= -1){
        *val = s->data[s->top];
        s->top--;
    }
}

// Jette un oeil au sommet.
void peek(stack *s, int *val){
    if(s->top > -1)
        *val = s->data[s->top];
}

// Désalloue la mémoire de la pile et met data à NULL, ainsi que la taille et le sommet à -1.
void stack_destroy(stack *s){
    free(s->data);
    s->data = NULL;
    s->capacity = -1;
    s->top = -1;
}