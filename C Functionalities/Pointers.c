#include <stdio.h>

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int *ptr;

    // Basic pointer initialization
    ptr = numbers; // ptr now points to the first element of the array
    printf("ptr points to the value %d\n", *ptr);

    // Pointer increment: moves the pointer to the next integer
    ptr++;
    printf("After increment, ptr points to the value %d\n", *ptr);

    // Pointer decrement: moves the pointer to the previous integer
    ptr--;
    printf("After decrement, ptr points to the value %d\n", *ptr);

    // Pointer addition: moves the pointer n integers forward
    ptr += 3;
    printf("After adding 3, ptr points to the value %d\n", *ptr);

    // Pointer subtraction: moves the pointer n integers backward
    ptr -= 2;
    printf("After subtracting 2, ptr points to the value %d\n", *ptr);

    // Pointer difference: find the offset between two pointers
    int *ptr2 = &numbers[4]; // Pointing to the last element
    int offset = ptr2 - ptr; // Should be 4 - 1 = 3
    printf("The offset between ptr2 and ptr is %d\n", offset);

    // Pointer to Pointer: pointer storing the address of another pointer
    int **pptr = &ptr;
    printf("Value where pptr is pointing to the address where ptr is pointing: %d\n", **pptr);

    // Array of pointers
    int *array_of_ptrs[5];
    for (int i = 0; i < 5; i++) {
        array_of_ptrs[i] = &numbers[i]; // or array_of_ptrs[i] = numbers + i;
    }
    printf("Value of the first element through array_of_ptrs: %d\n", *array_of_ptrs[0]);
    
    return 0;
}

