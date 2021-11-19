#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// m1 for ligne, call m2
// m2 for colonne, si fructueux original board = new
//                 sinon retourner en arrière et passer à la ligne suivante

void init_board(bool **board, int size_x, int size_y) {
    for (int i = 0; i < size_y; i++) {
        board[i] = malloc(size_x * sizeof(bool *));
        for (int j = 0; j < size_x; j++) {
            board[i][j] = false;
        }
    }
}

void free_board(bool **board, int size_y) {
    for (int i = 0; i < size_y; i++) {
        free(board[i]);
    }
}

void board_copy(bool **board_cpy, bool **board, int size_col, int size_line) {
    for (int i = 0; i < size_line; i++) {
        for (int j = 0; j < size_col; j++) {
            board_cpy[i][j] = board[i][j];
        }
    }
}

bool collision(int queen_x, int queen_y, int x, int y) {
    return y == queen_y || x == queen_x || abs(queen_y - y) == abs(queen_x - x);
}

void obstruct_board(bool **board, int width, int height, int x, int y) {
    for (int _y = 0; _y < height; _y++) {
        for (int _x = 0; _x < width; _x++) {
            if (collision(x, y, _x, _y)) {
                board[x][y] = true;
            }
        }
    }
}

void place_queen(bool **board, int x, int y) {
    board[y][x] = true;
}

void nb_solution(bool **board, int size, int line, int *counter) {
    for (int col = 0; col < size && line < size; col++) {
        if (board[line][col] == 0) {
            if (col < size-1) {
                bool **board_cpy = malloc(size * sizeof(bool *));
                init_board(board_cpy, size, size);
                board_copy(board_cpy, board, size, size);

                place_queen(board_cpy, col, line);
                obstruct_board(board_cpy, size, size, col, line);

                nb_solution(board_cpy, size, line + 1, counter);
                
                free_board(board_cpy, size);
                free(board_cpy);
            } else
                *counter = *counter + 1;
        }
    }
}

void chess_print(bool **board, int size) {
    for (int i = 0; i < size; i++) {
        printf("{");
        for (int j = 0; j < size; j++) {
            if (j == size - 1)
                printf("%d ", board[i][j]);
            else
                printf("%d, ", board[i][j]);
        }
        printf("}\n");
    }
}

int main() {
    int size = 5;
    bool **board = malloc(size * sizeof(bool *));
    init_board(board, size, size);

    int counter = 0;

    nb_solution(board, size, 0, &counter);
    chess_print(board, size);
    printf("counter %d\n", counter);

    free_board(board, size);
    free(board);
    return 0;
}