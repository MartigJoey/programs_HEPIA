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

  pretty_print(tree, 0);
  assert(tree_depth(tree) == 4);

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
  printf("Node balance %d\n", fe(tree));
  assert(fe(tree) == 2);

  assert(is_avl(tree) == 0);


  remove_element(tree, 14);
  insert(tree, 5);
  pretty_print(tree, 0);

  assert(is_avl(tree) == 1);

  tree_free(tree);

  // Test free
  tree_t* tree2 = create(5);

  insert(tree2, 4);
  insert(tree2, 6);

  remove_element(tree2, 5);
  remove_element(tree2, 4);

  tree_free(tree2);



  tree_t* tree3 = create(5);

  insert(tree3, 4);
  insert(tree3, 6);
  
  remove_element(tree3, 6);
  remove_element(tree3, 5);

  tree_free(tree3);

  tree_t* tree4 = create(5);

  insert(tree4, 6);
  insert(tree4, 10);

  pretty_print(tree4, 0);
  //tree4 = rotation_left(tree4);
  tree4 = balance_avl(tree4);

  pretty_print(tree4, 0);


  insert(tree4, 15);
  insert(tree4, 9);
  insert(tree4, 8);
  pretty_print(tree4, 0);
  tree4 = balance_avl(tree4);

  pretty_print(tree4, 0);

  tree_free(tree4);

  tree_t* tree5 = create(6);

  insert(tree5, 7);
  insert(tree5, 3);

  pretty_print(tree5, 0);


  insert(tree5, 1);
  insert(tree5, 4);
  insert(tree5, 5);
  pretty_print(tree5, 0);
  tree5 = balance_avl(tree5);

  pretty_print(tree5, 0);

  tree_free(tree5);


  tree_t* tree6 = create(15);
  insert(tree6, 20);
  insert(tree6, 6);
  insert(tree6, 7);
  insert(tree6, 3);

  pretty_print(tree6, 0);


  insert(tree6, 1);
  insert(tree6, 4);
  insert(tree6, 5);
  pretty_print(tree6, 0);
  tree6 = balance_avl(tree6);
  //tree6 = balance_avl(tree6);

  pretty_print_fe(tree6, 0);
  pretty_print(tree6, 0);
  tree_free(tree6);

  // Bug quand delete racine avec 1 enfant
  return EXIT_SUCCESS;
}
