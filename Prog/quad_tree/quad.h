#ifndef QUAD_H
#define QUAD_H

#include <stdbool.h>

typedef struct quad_tree_t{
    int val;
    struct quad_tree_t* children[4];
}quad_tree;

quad_tree* create_node(int value);
void tree_free(quad_tree* tree);
void to_matrix(quad_tree* qt, int row, int col, int** matrix);
quad_tree* to_quad_tree(int size, int** array);
void symetrie(quad_tree* tree);
void lossless_compression(quad_tree* qt);
//bool last_value(quad_tree* qt, int* val);
//bool is_last_branch(quad_tree* qt);

int tree_size(quad_tree* t);
void pretty_print(quad_tree* tree, int depth);
int tree_depth(quad_tree* tree);
quad_tree* insert(quad_tree* t, int value);
quad_tree* find(quad_tree* t, int value);
quad_tree* find_parent(quad_tree* t, int value);

void remove_element(quad_tree* t, int value);

bool is_present(quad_tree *tree, int val);
bool is_bst(quad_tree *tree);
quad_tree *find_min(quad_tree *tree);
quad_tree *find_max(quad_tree *tree);

#endif
