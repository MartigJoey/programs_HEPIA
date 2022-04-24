/**
 * @file tree_tests.c
 * @author Joey Martig
 * @brief Test unitaires du programme tree.
 * @date 24.04.2022
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main() {
  // Init
  tree_t* tree = create(5);

  // Test : Insert
  insert(tree, 2);
  insert(tree, 13);

  // Test : Size
  assert(tree_size(tree) == 3);

  // Test : RGD
  print_rgd(tree);

  insert(tree, 15);
  insert(tree, 14);
  insert(tree, 1);
  insert(tree, 7);
  insert(tree, 8);
  insert(tree, 6);

  printf("\n Gdr: \n");
  print_gdr(tree);
  printf("\n");
  printf("Rgd: \n");
  print_rgd(tree);
  printf("\n");

  assert(tree_depth(tree) == 7);

  tree_t* search = find(tree, 15);
  assert(search->value == 15);

  assert(is_present(tree, 8) == 1);
  assert(is_present(tree, 3) == 0);

  tree_t* min = find_min(tree);
  assert(min->value == 1);

  tree_t* max = find_max(tree);
  if (max != NULL)
    assert(max->value == 15);

  assert(is_bst(tree) == 1);

  insert(tree, 3);
  remove_element(tree, 13);
  assert(tree->right->value == 7);

  remove_element(tree, 5);
  assert(tree->value == 3);
  remove_element(tree, 3);
  assert(tree->value == 2);
  remove_element(tree, 2);
  assert(tree->value == 1);
  remove_element(tree, 1);
  assert(tree->value == 7);


  pretty_print(tree, 0);
  printf("%d\n", get_node_balance(tree));
  assert(get_node_balance(tree) == 2);

  assert(is_avl(tree) == 0);

  tree_free(tree);

  return EXIT_SUCCESS;
}
