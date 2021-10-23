#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X_SIZE 8
#define Y_SIZE 8

void fill(char tab[Y_SIZE][X_SIZE]) {
    for (int i = 0; i < Y_SIZE; i++) {
        for (int j = 0; j < X_SIZE; j++) {
            tab[i][j] = ' ';
        }
    }
}

void horizontal_pos(char tab[Y_SIZE][X_SIZE], int queen_y) {
    for (int x = 0; x < X_SIZE; x++) {
        tab[queen_y][x] = '*';
    }
}

void vertical_pos(char tab[Y_SIZE][X_SIZE], int queen_x) {
    for (int y = 0; y < Y_SIZE; y++) {
        tab[y][queen_x] = '*';
    }
}

void fill_positions(char tab[Y_SIZE][X_SIZE],
                    int queen_x, int queen_y,
                    char inc_x, char inc_y) {
    int x_max_size = X_SIZE;
    int y_max_size = Y_SIZE;
    if (inc_x == ' ')
        x_max_size = queen_x+1;

    if (inc_y == ' ')
        y_max_size = queen_y+1;

    for (int y = queen_y; y < y_max_size && y >= 0; y = inc_y == '+' ? y + 1 : y - 1) {
        for (int x = queen_x; x < x_max_size && x >= 0; x = inc_x == '+' ? x + 1 : x - 1) {
            tab[y][x] = '*';
        }
    }
}

void display(char tab[Y_SIZE][X_SIZE]) {
    for (int y = 0; y < Y_SIZE; y++) {
        for (int x = 0; x < X_SIZE; x++) {
            printf("%c ", tab[y][x]);
        }
        printf("\n");
    }
}

int main() {
    char tab[Y_SIZE][Y_SIZE];
    srand(time(NULL));
    int queen_x;
    int queen_y;
    scanf("%d %d", &queen_x, &queen_y);

    // FAIRE EN ENUM
    fill(tab);
    //horizontal_pos(tab, queen_y);
    //vertical_pos(tab, queen_x);
    //diagonal_pos(tab, queen_x, queen_y);
    fill_positions(tab, queen_x, queen_y, '+', ' ');
    //fill_positions(tab, queen_x, queen_y, '-', ' ');
    //fill_positions(tab, queen_x, queen_y, ' ', '+');
    //fill_positions(tab, queen_x, queen_y, ' ', '-');

    tab[queen_y][queen_x] = 'R';
    display(tab);
    // Display

    return 1;
}