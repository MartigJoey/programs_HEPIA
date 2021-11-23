/**
 * @file main.c
 * @author Joey Martig
 * @brief Programme utilisant la librairie main pour récupérer et trier une pile.
 * @date 23.11.2021
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void transfer_stack_top(stack *from_stack, stack *to_stack) {
    int value;
    pop(from_stack, &value);
    push(to_stack, value);
}

void transfer_to_left_stack(stack *left_stack, stack *right_stack){
    if(!is_empty(*right_stack)){
        transfer_stack_top(right_stack, left_stack);
        transfer_to_left_stack(left_stack, right_stack);
    }
}

void print_stack(stack *stc){
    if(!is_empty(*stc)){
        int value;
        pop(stc, &value);
        printf(" %d ", value);
        print_stack(stc);
        push(stc, value);
    }
}

int main(int argc, char **argv) {
    int value;
    int stack_size = atoi(argv[1]);
    if (stack_size < 1)
        return EXIT_FAILURE;

    stack *left_stack = malloc(sizeof(stack));
    stack *right_stack = malloc(sizeof(stack));

    stack_init(left_stack, stack_size);
    stack_init(right_stack, stack_size);

    for (int i = 2; i < stack_size + 2; i++) {
        int value = atoi(argv[i]);
        int left_stack_top, right_stack_top;
        peek(left_stack, &left_stack_top);
        peek(right_stack, &right_stack_top);

        if (is_empty(*left_stack) && is_empty(*right_stack))
            push(left_stack, value);
        else if(is_empty(*right_stack)){
            while(value > left_stack_top && !is_empty(*left_stack))
                transfer_stack_top(left_stack, right_stack);

            push(left_stack, value);
        }
        else {
            while ((value > left_stack_top || value < right_stack_top) && left_stack_top != right_stack_top) {
                if(value > left_stack_top)
                    transfer_stack_top(left_stack, right_stack);
                else if(value < right_stack_top)
                    transfer_stack_top(right_stack, left_stack);
                
                peek(left_stack, &left_stack_top);
                peek(right_stack, &right_stack_top);
            }
            push(left_stack, value);
        }
    }
    
    transfer_to_left_stack(left_stack, right_stack);
    print_stack(left_stack);
    printf("\n");

    stack_destroy(left_stack);
    stack_destroy(right_stack);

    free(left_stack);
    free(right_stack);
    return 0;
}