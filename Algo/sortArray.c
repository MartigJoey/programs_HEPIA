#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 8
#define MIN -100
#define RANGE 200
double array[ARRAY_SIZE];

int swapValues(int indexOne, int indexTwo)
{
  int temp = array[indexOne];
  array[indexOne] = array[indexTwo];
  array[indexTwo] = temp;
}

int createArray(){
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = rand() % RANGE + MIN;
    }
}

int sort(){
    for (int i = ARRAY_SIZE - 1; i > 1; i--)
    {
      for (int j = 0; j < i; j++)
      {
        if (array[j] > array[j + 1])
        {
          swapValues(j, j + 1);
        }
      }
    }
}

int isSorted(){
    printf("Le tableau est trié :");
    int current = array[0];
    bool isSorted = true;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (current <= array[i])
            current = array[i];
        else
            isSorted = false;
    }
    printf("%s\n", isSorted ? "oui" : "non");
}

int main(){
    createArray();
    sort();
    isSorted();

    printf("Le tableau trié:\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%lf\n", array[i]);
    }
    
    return 0;
}