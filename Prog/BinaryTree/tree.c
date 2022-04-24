#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

tree_t *create(int value) {
  tree_t *tree = (tree_t *)malloc(sizeof(tree_t));
  tree->value = value;
  tree->left = NULL;
  tree->right = NULL;
  return tree;
}

void tree_free(tree_t *tree) {
  if (tree->left != NULL)
    tree_free(tree->left);

  if (tree->right != NULL)
    tree_free(tree->right);

  free(tree);
}

int tree_size(tree_t *tree) {
  if(tree == NULL)
    return 0;

  int result = 1;
  if (tree->right != NULL)
    result += tree_size(tree->right);
  if (tree->left != NULL)
    result += tree_size(tree->left);
  return result;
}

int tree_depth(tree_t *tree) {
  if(tree == NULL)
    return 0;

  int result_left = 1;
  int result_right = 1;
  if (tree->right != NULL)
    result_right += tree_size(tree->right);
  if (tree->left != NULL)
    result_left += tree_size(tree->left);

  return result_left > result_right ? result_left : result_right;
}

void print_rgd(tree_t *tree) {
  printf("%d\n", tree->value);
  if (tree->left != NULL)
    print_rgd(tree->left);
  if (tree->right != NULL)
    print_rgd(tree->right);
}

void print_gdr(tree_t *tree) {
  if (tree->left != NULL)
    print_rgd(tree->left);
  if (tree->right != NULL)
    print_rgd(tree->right);
  printf("%d\n", tree->value);
}

void pretty_print(tree_t *tree, int depth) {
  if (tree->right != NULL)
    pretty_print(tree->right, depth + 1);

  for (int i = 0; i < depth * 7; i++)
    printf(" ");
  printf("%d\n", tree->value);

  if (tree->left != NULL)
    pretty_print(tree->left, depth + 1);
}

tree_t *insert(tree_t *tree, int value) {
  if (tree->value < value) {
    if (tree->right == NULL)
      tree->right = create(value);
    else
      insert(tree->right, value);
  } else if (tree->value > value) {
    if (tree->left == NULL)
      tree->left = create(value);
    else
      insert(tree->left, value);
  } else
    return create(value);
}

tree_t *find(tree_t *tree, int value) {
  if (tree->value == value)
    return tree;

  if (tree->value < value)
    return find(tree->right, value);
  else
    return find(tree->left, value);

  return NULL;
}

tree_t *find_parent(tree_t *tree, int value) {
  if ((tree->right != NULL && tree->right->value == value) || (tree->left != NULL && tree->left->value == value))
    return tree;
  else if (tree->value < value && tree->right != NULL)
    return find_parent(tree->right, value);
  else if (tree->value > value && tree->left != NULL)
    return find_parent(tree->left, value);
  else
    return NULL;
}

// Could reuse find()
bool is_present(tree_t *tree, int val) {
  bool result_left = false;
  bool result_right = false;
  if (tree->value == val)
    return true;

  if (tree->left != NULL)
    result_left = is_present(tree->left, val);

  if (tree->right != NULL)
    result_right = is_present(tree->right, val);

  return result_left == true || result_right == true ? true : false;
}

bool is_bst(tree_t *tree) {
  bool result_left = true;
  bool result_right = true;
  bool result = true;

  if (tree->left != NULL) {
    result_left = is_bst(tree->left);
    if (tree->left->value > tree->value)
      result = false;
  }

  if (tree->right != NULL) {
    result_right = is_bst(tree->right);
    if (tree->right->value < tree->value)
      result = false;
  }

  return result_left == false || result_right == false || result == false ? false : true;
}

tree_t *find_min(tree_t *tree) {
  if (tree->left != NULL)
    return find_min(tree->left);
  else
    return tree;
}

tree_t *find_max(tree_t *tree) {
  if (tree->right != NULL)
    return find_max(tree->right);
  else
    return tree;
}

void remove_element(tree_t *tree, int value) {
  tree_t *root_node = tree;
  tree = find_parent(tree, value);

  // Si ce n'est pas la racine
  if (tree != NULL) {
    tree_t *tree_remove = (tree_t *)malloc(sizeof(tree_t));

    // Si l'élément à retirer est à droite
    if (tree->right->value == value) {
      tree_remove = tree->right;

      // Place un nouveau noeud à la place
      if (tree_remove->left != NULL)
        tree->right = tree_remove->left;
      else if (tree_remove->right != NULL)
        tree->right = tree_remove->right;
      else
        tree->right = NULL;

      // Recole les liens du noeud supprimé au reste de l'arbre
      while (tree->right != NULL)
        tree = tree->right;

      if (tree != tree_remove->right)
        tree->right = tree_remove->right;
    } else if (tree->left->value == value) {
      tree_remove = tree->left;

      if (tree_remove->right != NULL)
        tree->left = tree_remove->right;
      else if (tree_remove->left != NULL)
        tree->left = tree_remove->left;
      else
        tree->left = NULL;

      while (tree->left != NULL)
        tree = tree->left;

      if (tree != tree_remove->left)
        tree->left = tree_remove->left;
    }
  } else {
    tree_t *new_root = (tree_t *)malloc(sizeof(tree_t));
    tree_t *new_root_p = NULL;  // parent

    if (root_node->left != NULL) {
      new_root = root_node->left;

      while (new_root->right != NULL) {
        new_root_p = new_root;
        new_root = new_root->right;
      }

      // SI new root a un enfant, le donner à droite de son parent
      if (new_root_p != NULL) {
        new_root_p->right = new_root->left;
      }

      if (new_root_p != NULL && new_root_p != new_root)
        root_node->left = new_root_p;
      else
        root_node->left = new_root->left;

      root_node->value = new_root->value;
      new_root->left = NULL;
      new_root->right = NULL;

    } else {
      root_node->value = root_node->right->value;
      root_node->left = root_node->right->left;
      root_node->right = root_node->right->right;
    }
  }
}


// AVL METHODS

bool is_avl(tree_t *tree){
  
}

int get_node_balance(tree_t *tree){
  int result = tree_depth(tree->right) - tree_depth(tree->left);

  if(result > 2)
    return 2;
  if(result < 2)
    return -2;
  
  return result;
}

tree_t* balance_avl(tree_t *tree){

}


/*
bool result_left = true;
  bool result_right = true;

  if (tree->left != NULL) {
    result_left = is_avl(tree->left);
    if(!result_left)
      return false;

    int depth_left = 0;
    int depth_right = 0;

    if(tree->left->left != NULL)
      depth_left = get_node_balance(tree->left->left);

    if(tree->left->right != NULL)
      depth_right = get_node_balance(tree->left->right);
    
    result_left = abs(abs(depth_left) - abs(depth_right)) > 1 ? false : true;
  }

  if (tree->right != NULL) {
    result_right = is_avl(tree->left);
    if(!result_right)
      return false;

    int depth_left = 0;
    int depth_right = 0;

    if(tree->left->left != NULL)
      depth_left = get_node_balance(tree->right->left);

    if(tree->left->right != NULL)
      depth_right = get_node_balance(tree->right->right);
    
    result_right = abs(abs(depth_left) - abs(depth_right)) > 1 ? false : true;
  }

  return result_left == false || result_right == false ? false : true;
*/