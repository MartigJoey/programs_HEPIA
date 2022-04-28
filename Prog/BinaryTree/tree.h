#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

typedef struct tree{
    int value;
    struct tree* left;
    struct tree* right;
} tree_t;

tree_t* create(int value);
void tree_free(tree_t* tree);
int tree_size(tree_t* t);
void pretty_print(tree_t* tree, int depth);
void pretty_print_fe(tree_t *tree, int depth);
int tree_depth(tree_t* tree);
void print_rgd(tree_t* t);
void print_gdr(tree_t* t);
tree_t* insert(tree_t* t, int value);
tree_t* find(tree_t* t, int value);
tree_t* find_parent(tree_t* t, int value);

void remove_element(tree_t* t, int value);

bool is_present(tree_t *tree, int val);
bool is_bst(tree_t *tree);
tree_t *find_min(tree_t *tree);
tree_t *find_max(tree_t *tree);

bool is_avl(tree_t *tree);
int fe(tree_t *tree);
tree_t* balance_avl(tree_t *tree);
tree_t* rotation_left(tree_t *tree);
tree_t* rotation_right(tree_t *tree);


#endif