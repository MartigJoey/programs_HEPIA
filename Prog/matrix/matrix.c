#include "matrix.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Création d’une nouvelle matrice de m lignes et n colonnes et allocation de la mémoire
error_code matrix_alloc(matrix *mat, int32_t m, int32_t n) {
    mat->m = m;
    mat->n = n;
    mat->data = malloc(m * sizeof(int32_t*));
    for (int i = 0; i < m; i++) {
        mat->data[i] = malloc(n * sizeof(int32_t*));
    }

    return ok;
}

// Allocation et initialisation à une valeur, val, d’une nouvelle matrice de m lignes et n colonnes
error_code matrix_init(matrix *mat, int32_t m, int32_t n, int32_t val) {
    mat->data[m][n] = val;

    return ok;
}

// Libération de la mémoire de la matrice en argument, le pointeur vers les données est mis à NULL, le nombre de lignes et de colonnes sont mis à -1
error_code matrix_destroy(matrix *mat) {
    for (int i = 0; i < mat->m; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    mat->data = NULL;

    mat->m = -1;
    mat->n = -1;

    return ok;
}

// Allocation d’une matrice, et initialisation de ses valeurs à partir d’un tableau de taille s = m*n
error_code matrix_init_from_array(matrix *mat, int32_t m, int32_t n, int32_t data[], int32_t s) {
    mat->m = m;
    mat->n = n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int32_t data_i = i * m + j;
            if (data_i > s)
                return err;
            mat->data[i][j] = data[data_i];
        }
    }

    return ok;
}

// Création du clone d’une matrice, la nouvelle matrice est une copie de la matrice d’origine
error_code matrix_clone(matrix *cloned, const matrix mat) {
    cloned->m = mat.m;
    cloned->n = mat.n;
    cloned->data = malloc(mat.m * sizeof(int32_t*));
    for (int i = 0; i < mat.m; i++) {
        cloned->data[i] = malloc(mat.n * sizeof(int32_t*));
        for (int j = 0; j < mat.n; j++) {
            cloned->data[i][j] = mat.data[i][j];
        }
    }

    error_code result_code = ok;
    return result_code;
}

// Création de la matrice transposée d’une matrice, la nouvelle matrice est une copie de la matrice originale ou les lignes et les colonnes sont échangées
error_code matrix_transpose(matrix *transposed, const matrix mat) {
    transposed->m = mat.n;
    transposed->n = mat.m;
    transposed->data = malloc(transposed->m * sizeof(int32_t*));
    for (int i_m = 0; i_m < transposed->m; i_m++) {
        transposed->data[i_m] = malloc(transposed->n * sizeof(int32_t*));
        for (int j_n = 0; j_n < transposed->n; j_n++) {
            transposed->data[i_m][j_n] = mat.data[j_n][i_m];
        }
    }

    return ok;
}

// Affichage d’une matrice (très utile pour le débogage)
error_code matrix_print(const matrix mat) {
    for (int i = 0; i < mat.m; i++) {
        printf("{");
        for (int j = 0; j < mat.n; j++) {
            if(j == mat.n-1)
                printf("%d ", mat.data[i][j]);
            else
                printf("%d, ", mat.data[i][j]);
        }
        printf("}\n");
    }

    return ok;
}

// Extraction d’une sous-matrice d’une matrice
error_code matrix_extract_submatrix(matrix *sub, const matrix mat, int32_t m0, int32_t m1, int32_t n0, int32_t n1) {
    if (m0 < 0 || mat.m < m1 ||
        n0 < 0 || mat.n < n1)
        return err;

    sub->m = m1 - m0;
    sub->n = n1 - n0;

    sub->data = malloc(sub->m * sizeof(int32_t*));
    for (int i = 0; i < mat.m; i++) {
        if(m0 <= i && i <= m1){
            sub->data[i-m0] = malloc(sub->n * sizeof(int32_t*));
            for (int j = 0; j < mat.n; j++) {
                if (n0 <= j && j <= n1) {
                    if(i - m0 > m1 || j - n0 > n1)
                        return err;

                    sub->data[i - m0][j - n0] = mat.data[j][i];
                }
            }
        }
    }
    return ok;
}

// Test de l’égalité de deux matrices
bool matrix_is_equal(matrix mat1, matrix mat2) {
    if (mat1.m != mat2.m || mat1.n != mat2.n)
        return false;

    int m = mat1.m, n = mat1.n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat1.data[i][j] != mat2.data[i][j])
                return false;
        }
    }
    return true;
}

// Récupération de l’élément [ix][iy] de la matrice de façon sûre (vérification
// des dépassements de capacité par exemple) et copie dans elem
error_code matrix_get(int32_t *elem, const matrix mat, int32_t ix, int32_t iy) {
    if (ix > mat.m || iy > mat.n)
        return err;

    *elem = mat.data[ix][iy];
    return ok;
}

// Modification d’un élément [ix][iy] de la matrice de façon sûre (vérification
// des dépassements de capacité par exemple)
error_code matrix_set(matrix mat, int32_t ix, int32_t iy, int32_t elem) {
    if (ix > mat.m || iy > mat.n)
        return err;

    mat.data[ix][iy] = elem;
    return ok;
}