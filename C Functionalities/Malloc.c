#include <stdio.h>
#include <stdlib.h>

int main() {
    // Using malloc to allocate an integer
    int *singleInt = (int *)malloc(sizeof(int));
    if (singleInt == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    *singleInt = 42;
    printf("Single int: %d\n", *singleInt);
    free(singleInt);

    // Using calloc to allocate an array of integers, initialized to zero
    int *intArray = (int *)calloc(5, sizeof(int));
    if (intArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    intArray[2] = 5;
    printf("Array element at index 2: %d\n", intArray[2]);
    free(intArray);

    // Using realloc to resize an allocated array
    int *resizedArray = (int *)malloc(5 * sizeof(int));
    if (resizedArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 5; ++i) {
        resizedArray[i] = i;
    }
    resizedArray = (int *)realloc(resizedArray, 10 * sizeof(int));
    if (resizedArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    resizedArray[9] = 9;
    printf("Resized array element at index 9: %d\n", resizedArray[9]);
    free(resizedArray);

    // Using malloc to allocate a block of memory for a structure
    struct Point {
        int x;
        int y;
    };
    struct Point *p = (struct Point *)malloc(sizeof(struct Point));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    p->x = 1;
    p->y = 2;
    printf("Point coordinates: (%d, %d)\n", p->x, p->y);
    free(p);

    return 0;
}

