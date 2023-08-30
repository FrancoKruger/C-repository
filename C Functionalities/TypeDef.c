#include <stdio.h>

// Typedef for primitive types
typedef int Integer;
typedef float Real;

// Typedef for array type
typedef int IntArray[5];

// Typedef for pointer type
typedef char *String;

// Typedef for function pointer
typedef int (*FuncPtr)(int, int);

int add(int a, int b) {
    return a + b;
}

int main() {
    // Using Integer
    Integer x = 10;
    Integer y = 20;
    Integer sum = x + y;
    printf("Integer Sum: %d\n", sum);
    
    // Using Real
    Real a = 5.5;
    Real b = 6.5;
    Real result = a + b;
    printf("Real Sum: %.2f\n", result);

    // Using IntArray
    IntArray arr = {1, 2, 3, 4, 5};
    for (Integer i = 0; i < 5; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Using String
    String str = "Hello, World!";
    printf("String: %s\n", str);

    // Using FuncPtr
    FuncPtr addFunc = add;
    Integer resultFunc = addFunc(3, 4);
    printf("Result from function pointer: %d\n", resultFunc);

    return 0;
}

