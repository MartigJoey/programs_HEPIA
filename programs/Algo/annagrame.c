#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

int swapValues(char *array, int indexOne, int indexTwo) {
    int temp = array[indexOne];
    array[indexOne] = array[indexTwo];
    array[indexTwo] = temp;
    return 0;
}

int sort(char *array) {
    for (int i = ARRAY_SIZE - 1; i > 1; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j + 1]) {
                swapValues(array, j, j + 1);
            }
        }
    }
    return 0;
}

int main() {
    char str1[ARRAY_SIZE] = "tutute";
    char str2[ARRAY_SIZE] = "tttuue";

    sort(str1);
    sort(str2);

    bool isA = true;

    for (int i = ARRAY_SIZE; str1[i] != '\0'; i--) {
        printf("%c %c  \n", str1[i], str2[i]);
        if (str1[i] != str2[i])
            isA = false;
    }

    printf("Is anagramme ? %s\n", isA ? "yup" : "nop");

    return 0;
}