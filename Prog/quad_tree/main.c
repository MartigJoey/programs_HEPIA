#include <stdio.h>
#include <stdlib.h>

#include "quad.h"
#define SIZE 4

int** alloc_array_(int size){
    int** array = malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++)
    {
        array[i] = malloc(sizeof(int*) * size);
    }
    return array;
}

int** copy_array(int size, int mat[size][size]){
    int** array = alloc_array_(size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            array[i][j] = mat[i][j];
        }
        
    }
    return array;
}

void free_array_(int size, int** mat){
    for (int i = 0; i < size; i++){
        free(mat[i]);
    }
    free(mat);
}

int main() {
	int array_[SIZE][SIZE] = {{0,0,1,1},
			{0,0,1,0},
			{1,0,1,0},
			{0,1,0,1}};

	int** array = copy_array(SIZE, array_);

    quad_tree* tree = create_node(0);

  // matrix* to_matrix(quad_tree* tree);

    tree = to_quad_tree(SIZE, array);
	pretty_print(tree, 0);
  // quad_tree* symetrie(quad_tree* tree);

  // quad_tree* compress(quad_tree* tree);

	free_array_(SIZE, array);
    tree_free(tree);

  return EXIT_SUCCESS;
}
