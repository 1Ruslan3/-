#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 5 

void RandGenerate(int*);

void minmaxValue(int*);

int main(void) {
    int array[SIZE] = {NULL};
    int counter;
    srand(time(NULL));
    RandGenerate(array);
    minmaxValue(array);
    int q;
    printf("New array:\n[ ");
    for (q = 0; q <= SIZE - 1; q++) {
        printf("%d ", array[q]);
    }
    printf("]");
    return 0;
}

void RandGenerate(int* arrayPtr)
{
    int i;
    for (i = 0; i <= SIZE - 1; i++) {
        arrayPtr[i] = rand();
    }

    int q;
    printf("Old array:\n[ ");
    for (q = 0; q <= SIZE - 1; q++) {
        printf("%d ", arrayPtr[q]);
    }
    printf("]\n");
}



void minmaxValue(int* arrayPtr)
{
    
    int min = 2147483647; int max = -1;

    int max_i; int min_i; int j;
   
    for (j = 0; j <= SIZE - 1; j++) {
        if (arrayPtr[j] < min) {
            min = arrayPtr[j];
            min_i = j;
        }
        if (arrayPtr[j] > max) {
            max = arrayPtr[j];
            max_i = j;
        }
    }
   
    int hold;
    hold = arrayPtr[max_i];
    arrayPtr[max_i] = arrayPtr[min_i];
    arrayPtr[min_i] = hold;
}