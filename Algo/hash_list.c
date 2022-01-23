#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 13

struct hash_list {
   char  key;
   int   value;
} hash_list;

int get_index(int k){
    return k % LIST_SIZE;
}

int main(){
    char keys[] = {'R', 'E', 'C', 'O', 'U', 'P', 'A', 'N', 'T'};
    hash_list lst = malloc(sizeof(hash_list)*13);

    for (int i = 0; keys[i] < '\0'; i++)
    {
        if(lst[get_index(keys[i])].key == NULL){
            lst[get_index(keys[i])].key = keys[i];
            lst[get_index(keys[i])].value = 0;
        }else{
            int j;
            for (j = i; lst[get_index(keys[j])].key != NULL; j++)
            lst[get_index(keys[i])].key = keys[j];
            lst[get_index(keys[i])].value = 0;
        }
    }
    
    return EXIT_SUCCESS;
}