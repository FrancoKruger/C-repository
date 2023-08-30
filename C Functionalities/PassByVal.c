#include <stdio.h>

// Function to modify value, demonstrates pass-by-value
void modifyValue(int x) {
    x = x * 2;
    printf("Inside modifyValue: %d\n", x);
}

// Function to modify value using pointer, demonstrates pass-by-reference
void modifyValueByReference(int *x) {
    *x = *x * 2;
    printf("Inside modifyValueByReference: %d\n", *x);
}

int main() {
    int a = 10;

    printf("Original value of a: %d\n", a);

    // Passing by value, original 'a' won't change
    modifyValue(a);
    printf("After modifyValue, value of a: %d\n", a);

    // Passing by reference, original 'a' will be modified
    // Using '&' to pass the address of 'a'
    modifyValueByReference(&a);
    printf("After modifyValueByReference, value of a: %d\n", a);

    return 0;
}

