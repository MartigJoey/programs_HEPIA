#ifndef TREE_H
#define TREE_H

typedef struct tree{
    int value;
    tree* left;
    tree* right;
} tree_t;

tree create(int value);
tree tree_free(tree);
int tree_size(tree t);
void print_rgd(tree t);
void print_gdr(tree t);
tree insert(tree t, int value);
tree new_tree(int value);
tree find(tree t, int value);
tree find_parent(tree t, int value);
void remove(tree t, int value);

#endif