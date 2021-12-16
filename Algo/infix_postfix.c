#include <stdio.h>
#include <stdlib.h>

char *infix_to_postfix(char *infix){
    for (int i = 0; i < strlen(infix); i++)
    {
        if (is_operand(infix[i])) {
        // we just add operands in the new postfix string
        } else if (infix[i] == '(') {
        // we push opening parenthesis into the stack
        stack_push(&s, infix[i]);
        } else if (infix[i] == ')') {
        // we pop everything into the postfix
        } else if (is_operator(infix[i])) {
        // this is an operator. We add it to the postfix based
        // on the priority of what is already in the stack and push it
        }
    }
    

}

int main(){

    return EXIT_SUCCESS;
}