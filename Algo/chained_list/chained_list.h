/**
 * @file list.h
 * @author Jules Stähli, Quentin Fasler, Joey Martig, Dario Genga
 * @date 2021-12-22
 * @version 2.0
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct node  node; 
struct node { 
    int item; 
    node *next;
    node *previous; 
}; 

typedef struct list list; 
struct list { 
    node *first; 
    node *last; 
    int length; 
};

list *list_init();
int list_is_empty(list *list);
void list_push(list *list, int value);
void list_insert_at(list *list, int index, int value);
void list_unshift(list *list, int value);
int list_at(list *list, int index);
void list_each(list *list, void (*func)(int));
int list_length(list *list);
int list_peek(list *list);
int list_remove_at(list *list, int index);
int list_pop(list *list);
int list_shift(list *list);
list *list_copy(list *list);
list *list_map(list *list, int (*func)(int));
int *list_to_array(list *list);
void list_clear(list *list);
list *list_from_array(int *array, int length);
void list_free(list *list);