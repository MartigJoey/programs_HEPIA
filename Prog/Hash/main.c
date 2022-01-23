#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(){
  hm *test = hm_create(5);
  //printf("\n%d\n", key[0]);
  test = hm_set(test, "This", "is");
  hm_print(test);
  printf("get_val: %s\n", hm_get(test, "This"));
  printf("Remove_val: %s\n", hm_rm(test, "This"));
  hm_destroy(&test);
}