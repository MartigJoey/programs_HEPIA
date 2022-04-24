#include <stdio.h>

#include "tree.h"

int main() {
  tree_t* tree = create(5);
  insert(tree, 2);
  insert(tree, 13);
  printf("Size: %d\n", tree_size(tree));

  printf("Rgd: \n");
  print_rgd(tree);

  insert(tree, 15);
  insert(tree, 14);
  insert(tree, 1);
  insert(tree, 7);
  insert(tree, 8);
  insert(tree, 6);

  insert(tree, 3);
  remove_element(tree, 13);
  remove_element(tree, 5);
  remove_element(tree, 3);
  remove_element(tree, 2);
  remove_element(tree, 1);
  pretty_print(tree, 0);

  tree_free(tree);

  return 0;
}