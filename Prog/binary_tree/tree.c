#include <stdio.h>
#include "tree.h"

tree_t* create(int value){

}

tree_t* tree_free(tree_t* tree){

}

int tree_size(tree_t* tree){
    int result = 1;
    if(tree->right != NULL)
        result += tree_size(tree->right);
    if(tree->left != NULL)
        result += tree_size(tree->left);
    return result;
}

void print_rgd(tree_t* tree){
    print(tree->value);
    if(tree->left != NULL)
        print_rgd(tree->left);
    if(tree->right != NULL)
        print_rgd(tree->right);
}

void print_gdr(tree_t* tree){
    if(tree->left != NULL)
        print_rgd(tree->left);
    if(tree->right != NULL)
        print_rgd(right->left);
    print(tree->value);
}

tree_t* insert(tree_t* tree, int value){
    if(tree->value < value){
        if(tree->right == NULL)
            tree->right = new(value);
        else 
            insert(tree->right, value);
    }else if(tree->value > value){
        if(tree->left == NULL)
            tree->left = new(value);
        else insert(tree->left, value);
    }else
        return new(value);
}

tree_t* new(int value){
    tree_t* tree = malloc;
    tree->value = value;
    tree->right = NULL;
    tree->left = NULL;
    return tree;
}

tree_t* find(tree_t* tree, int value){
    if(tree == value)
        return tree;

    if(tree < value)
        return find(tree->right, value);
    else
        return find(tree->left, value);
    
    return NULL;
}

tree_t* find_parent(tree_t* tree, int value){
    if(tree->right == value || tree->left == value)
        return tree;
    else if(tree->value < value && tree->right != NULL)
        return find_parent(tree->right, value);
    else if(tree->value > value && tree->left != NULL)
        return find_parent(tree->left, value);
    else
        return NULL;
}

void remove(tree_t* tree, int value){
    tree = find_parent(tree, value);
    tree_t* tree_remove = malloc;

    if(tree->right->value == value){
        tree_remove = tree->right;

        if(tree_remove->left != NULL)
            tree->right = tree_remove->left;
        else if(tree_remove->right != NULL)
            tree->right = tree_remove->right;
        else
            tree->right = NULL;

        while(tree->right != NULL)
            tree = tree->right;
        
        tree->right = tree_remove->right;           
    }else if(tree->left->value == value){
        tree_remove = tree->left;

        if(tree_remove->right != NULL)
            tree->left = tree_remove->right;
        else if(tree_remove->left != NULL)
            tree->left = tree_remove->left;
        else
            tree->left = NULL;

        while(tree->left != NULL)
            tree = tree->left;
        
        tree->left = tree_remove->left;           
    }
}