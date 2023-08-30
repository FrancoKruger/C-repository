#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function to sort integers
int compareInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Comparison function to sort strings
int compareStr(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    // Array of integers
    int intArr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(intArr) / sizeof(intArr[0]);

    qsort(intArr, n, sizeof(int), compareInt);
    printf("Sorted integer array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", intArr[i]);
    }
    printf("\n");

    // Array of strings
    const char *strArr[] = {"Apple", "Orange", "Banana", "Mango"};
    int strSize = sizeof(strArr) / sizeof(strArr[0]);

    qsort(strArr, strSize, sizeof(const char *), compareStr);
    printf("Sorted string array: ");
    for (int i = 0; i < strSize; ++i) {
        printf("%s ", strArr[i]);
    }
    printf("\n");

    // Using bsearch
    int key = 5;
    int *found = (int *)bsearch(&key, intArr, n, sizeof(int), compareInt);
    if (found != NULL) {
        printf("Value %d found\n", *found);
    } else {
        printf("Value %d not found\n", key);
    }

    return 0;
}

