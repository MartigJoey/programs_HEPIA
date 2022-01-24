#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hash.h"

#define PHONE_NUMBER_MAX_LENGTH 30 + 1
#define NAME_MAX_LENGTH 40 + 1

void test_lib(){
  hm *test = hm_create(5);
  test = hm_set(test, "This", "is");
  test = hm_set(test, "This", "are");
  test = hm_set(test, "Thi", "is");
  test = hm_set(test, "Thiss", "the");
  test = hm_set(test, "Thisss", "thec");
  hm_print(test);
  printf("get_val: %s\n", hm_get(test, "This"));

  char *str_rm = hm_rm(test, "This");
  printf("Remove_val: %s\n",str_rm);
  printf("get_val: %s\n", hm_get(test, "This"));

  char* str = hm_to_str(test);
  printf("To_str: \n%s\n", str);
  free(str);
  free(str_rm);
  hm_destroy(&test);
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}


int main(){
  hm *phonebook = hm_create(10);
  while(true){
    char user_choice;
    printf("\nQue souhaitez vous faire ?\na: Ajouter\nd: Supprimer\nr:Rechercher\nf:Afficher\nq:quitter\n");
    scanf("%c", &user_choice);
    clear_buffer();
    char* phone_nb = (char *)malloc(sizeof(char) * PHONE_NUMBER_MAX_LENGTH);
    char* name = (char *)malloc(sizeof(char) * NAME_MAX_LENGTH);
    switch(user_choice){
      case 'a': ;
        printf("Numéro de téléphone: \n");
        scanf("%s", phone_nb);
        clear_buffer();
        printf("Nom: \n");
        scanf("%s", name);
        clear_buffer();

        phonebook = hm_set(phonebook, phone_nb, name);
        break;
      case 'd': ;
        printf("Numéro de téléphone: \n");
        scanf("%s", phone_nb);
        clear_buffer();

        char *removed = hm_rm(phonebook, phone_nb);
        printf("Nom: %s\n", removed);
        free(removed);
        break;
      case 'r': ;
        printf("Numéro de téléphone: \n");
        scanf("%s", phone_nb);
        clear_buffer();

        printf("Nom: %s\n", hm_get(phonebook, phone_nb));
        break;
      case 'f': ;
        hm_print(phonebook);
        break;
      default:
        free(phone_nb);
        free(name);
        hm_destroy(&phonebook);
        return EXIT_SUCCESS;
        break;
    }
    free(phone_nb);
    free(name);
  }
}