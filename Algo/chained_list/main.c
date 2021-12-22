/**
 * @file list.h
 * @author Jules Stähli, Quentin Fasler, Joey Martig, Dario Genga
 * @date 2021-12-22
 * @version 2.0
 */
#include <stdio.h>
#include "chained_list.h"

void print_item(int item) {
    printf("%d\n", item);
}

int double_int(int x) {
    return x * 2;
}


int main(){
    list *li = list_init();
    list_push(li, 1);
    list_push(li, 2);
    list_push(li, 3);

    list_unshift(li, 4);
    list_unshift(li, 5);
    list_unshift(li, 6);

    list_insert_at(li, 3, 7);

    printf("Pop: %d\n", list_pop(li));

    printf("Remove at 2: %d\n", list_remove_at(li, 2));

    printf("Shift: %d\n", list_shift(li));

    list_each(li, print_item);
    printf("Length: %d\n\n", list_length(li));

    int *array = list_to_array(li);
    printf("Array\n");
    for (int i = 0; i < li->length; i++) {
        printf("%d\n", array[i]);
    }

    printf("Clear\n");
    list_clear(li);
    printf("Length %d\n", list_length(li));


    list_free(li);
    free(array);

    return EXIT_SUCCESS;
}