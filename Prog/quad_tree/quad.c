#include "quad.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

quad_tree* create_node(int value) {
    quad_tree* node = calloc(1, sizeof(quad_tree));
    node->val = value;
    return node;
}

quad_tree* create_childrens(int value[4]) {
    quad_tree* node = calloc(4, sizeof(quad_tree));

    for (size_t i = 0; i < 4; i++) {
        node[i].val = value[i];
    }

    return node;
}

void tree_free(quad_tree* tree) {
    for (size_t i = 0; i < 4; i++) {
        if (tree->children[i] != NULL)
            tree_free(tree->children[i]);
    }

    free(tree);
}

int* to_matrix(quad_tree* tree) {
}

int** alloc_array(int size) {
    int** array = malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        array[i] = malloc(sizeof(int*) * size);
    }
    return array;
}

int** copy_array_range(int size, int** mat, int start_x, int start_y, int new_size) {
    int** array = alloc_array(new_size);

    for (int i = 0; i < new_size; i++) {
        for (int j = 0; j < new_size; j++) {
            array[i][j] = mat[start_y + i][start_x + j];
        }
    }
    return array;
}

void free_array(int size, int** mat) {
    for (int i = 0; i < size; i++) {
        free(mat[i]);
    }
    free(mat);
}

quad_tree* to_quad_tree(int size, int** mat) {
    quad_tree* tree = create_node(0);

    if (size == 2) {
        tree->children[0] = create_node(mat[0][0]);
        tree->children[1] = create_node(mat[0][1]);
        tree->children[2] = create_node(mat[1][0]);
        tree->children[3] = create_node(mat[1][1]);
    } else {
        int new_size = size / 2;

        int** new_mat = copy_array_range(size, mat, 0, 0, new_size);
        // printf("allo %d\n",new_mat[0][0]);
        // printf("allo %d\n",new_mat[1][0]);
        // printf("allo %d\n",new_mat[0][1]);
        // printf("allo %d\n\n",new_mat[1][1]);
        tree->children[0] = to_quad_tree(new_size, new_mat);  // top left
        free_array(new_size, new_mat);

        new_mat = copy_array_range(size, mat, new_size, 0, new_size);
        tree->children[1] = to_quad_tree(new_size, new_mat);  // top right
        free_array(new_size, new_mat);

        new_mat = copy_array_range(size, mat, 0, new_size, new_size);
        tree->children[2] = to_quad_tree(new_size, new_mat);  // bottom left
        free_array(new_size, new_mat);

        new_mat = copy_array_range(size, mat, new_size, new_size, new_size);
        tree->children[3] = to_quad_tree(new_size, new_mat);  // bottom right
        free_array(new_size, new_mat);
    }
    return tree;
}

void symetrie(quad_tree* tree) {
    for (size_t i = 0; i < 4; i++) {
        if (tree->children[i] != NULL)
            symetrie(tree->children[i]);
    }

    if (tree->children[0] != NULL) {
        quad_tree* tmp = tree->children[0];
        tree->children[0] = tree->children[1];
        tree->children[1] = tmp;
        tmp = tree->children[2];
        tree->children[2] = tree->children[3];
        tree->children[3] = tmp;
    }
}

quad_tree* compress(quad_tree* tree) {
}

void pretty_print(quad_tree* tree, int depth) {
    if (!depth)
        printf("_____________________\n");

    for (int i = 0; i < 2; i++) {
        if (tree->children[i] != NULL)
            pretty_print(tree->children[i], depth + 1);
    }

    for (int i = 0; i < depth * 7; i++)
        printf(" ");

    if (tree->children[0] == NULL)
        printf("%d\n", tree->val);
    else
        printf("o\n");

    for (int i = 2; i < 4; i++) {
        if (tree->children[i] != NULL)
            pretty_print(tree->children[i], depth + 1);

        if(i == 3 && tree->children[0] != NULL && tree->children[0]->children[0] == NULL)
            printf("\n");
    }
}

/*
quad_tree* remove_node(quad_tree* tree) {
}

int tree_size(quad_tree* t) {
}

int tree_depth(quad_tree* tree) {
}

quad_tree* insert(quad_tree* t, int value) {
}

quad_tree* find(quad_tree* t, int value) {
}

quad_tree* find_parent(quad_tree* t, int value) {
}

void remove_element(quad_tree* t, int value) {
}
*/
