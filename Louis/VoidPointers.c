#include <stdio.h>
#include <stdlib.h>

// Function to display integer
void displayInt(void *ptr) {
    int *iptr = (int *)ptr;
    printf("Integer: %d\n", *iptr);
}

// Function to display float
void displayFloat(void *ptr) {
    float *fptr = (float *)ptr;
    printf("Float: %f\n", *fptr);
}

// Function to display char
void displayChar(void *ptr) {
    char *cptr = (char *)ptr;
    printf("Char: %c\n", *cptr);
}

int main() {
    int i = 5;
    float f = 3.14;
    char c = 'A';

    void *vptr;

    // Demonstrate void pointer with integer
    vptr = &i;
    displayInt(vptr);

    // Demonstrate void pointer with float
    vptr = &f;
    displayFloat(vptr);

    // Demonstrate void pointer with char
    vptr = &c;
    displayChar(vptr);

    return 0;
}

