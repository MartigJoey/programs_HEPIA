/**
 * @file list.h
 * @author Jules Stähli, Quentin Fasler, Joey Martig, Dario Genga
 * @date 2021-12-22
 * @version 2.0
 */

#include <stdlib.h>
#include <stdio.h>
#include "chained_list.h"

list *list_init() { 
    list *lst = malloc(sizeof(list)); 
    lst->first = NULL; 
    lst->last = NULL;  
    lst->length = 0; 
    return lst; 
}

int list_is_empty(list *list) { 
    return list->first == NULL && list->last == NULL; 
} 

void list_push(list *lst, int value) { 
    node *tmp = malloc(sizeof(node )); 
    tmp->item = value; 
    tmp->next = NULL; 
    if (list_is_empty(lst)) { 
        tmp->previous = NULL; 
        lst->last = lst->first = tmp; 
    } else { 
        tmp->previous = lst->last; 
        lst->last = lst->last->next = tmp; 
    }
    lst->length++; 
} 

void list_insert_at(list *lst, int index, int value) { 
    int i = 0; 
    node *current = lst->first; 
    while (current != NULL || i == 0) { 
        if (i == index) { 
            node *tmp = malloc(sizeof(node )); 
            tmp->item = value; 
            if (current == NULL) { 
                tmp->next = tmp->previous = NULL; 
                lst->first = lst->last = tmp; 
            } else if ((current->previous == NULL && current->next == NULL) || current->previous == NULL) { 
                lst->first = current->previous = tmp; 
                tmp->next = current; 
                tmp->previous = NULL; 
            } else { 
               current->previous->next = tmp; 
               tmp->previous = current->previous; 
               current->previous = tmp; 
               tmp->next = current; 
            } 
            lst->length++; 
        }
        if (current != NULL) { 
            current = current->next; 
        } 
        i++; 
    } 
    if (index == i) { 
        list_push(lst, value); 
    } 
}

void list_unshift(list *list, int value) { 
   list_insert_at(list, 0, value); 
} 

int list_at(list *lst, int index) { 
   int i = 0;                          
   for (node *current = lst->first; current != NULL; current = current->next) { 
        if (i == index) { 
            return current->item; 
        } 
        i++; 
   }  
   return lst->last->item; 
}

void list_each(list *lst, void (*func)(int)) { 
    for (node *current = lst->first; current != NULL; current = current->next) { 
        func(current->item); 
    } 
}

int list_length(list *lst) { 
    int i = 0; 
    for (node *current = lst->first; current != NULL; current = current->next) {i++;} 
    return i; 
}

int list_peek(list *lst) { 
    return lst->last->item; 
}

int list_remove_at(list *lst, int index) { 
    int i = 0; 
    for (node *current = lst->first; current != NULL; current = current->next) { 
        if (i == index) { 
            int value = current->item; 
            if (current->previous == NULL) { 
               lst->first = current->next; 
               current->next->previous = NULL; 
            } else if (current->next == NULL) { 
                lst->last = current->previous; 
                current->previous->next = NULL; 
            } else { 
                current->previous->next = current->next; 
                current->next->previous = current->previous; 
            } 
            free(current); 
            lst->length--; 
            return value; 
        } 
        i++; 
    } 
    return lst->last->item; 
}

int list_pop(list *lst) {
    int value = lst->last->item; 
    if (lst->first == lst->last) { 
        free(lst->last); 
        lst->first = lst->last = NULL; 
    } else { 
        lst->last = lst->last->previous; 
        free(lst->last->next); 
        lst->last->next = NULL; 
    } 
    lst->length--; 
    return value; 
} 

int list_shift(list *lst) { 
    return list_remove_at(lst, 0); 
}

list *list_copy(list *lst) { 
    list *copy = list_init(); 
    for (node *current = lst->first; current != NULL; current = current->next) { 
        list_push(copy, current->item); 
    } 
    return copy; 
}

list *list_map(list *lst, int (*func)(int)) { 
    list *copy = list_init(); 
    for (node *current = lst->first; current != NULL; current = current->next) { 
        list_push(copy, func(current->item)); 
    } 
    return copy; 
} 

int *list_to_array(list *lst) { 
    int *array = malloc(sizeof(int) * lst->length); 
    int i = 0; 
    for (node *current = lst->first; current != NULL; current = current->next) { 
        array[i] = current->item; 
        i++; 
    } 
    return array;
} 

void list_clear(list *lst) { 
    while (!list_is_empty(lst)) { 
        list_pop(lst); 
    } 
}

list *list_from_array(int *array, int length) { 
    list *lst = list_init(); 
    for (int i = 0; i < length; i++) { 
        list_push(lst, array[i]); 
    } 
    return lst; 
}

void list_free(list *lst) { 
    node  *current = lst->first; 
    node  *next; 
    while (current != NULL) { 
        next = current->next; 
        free(current); 
        current = next; 
    } 
    lst->first = NULL; 
    lst->last = NULL; 
    lst->length = 0; 
    free(lst); 
}