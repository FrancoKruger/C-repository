#include <stdio.h>

// Global variable: Accessible from all functions within this file
int globalVariable = 100;

// External variable: Could be accessible from other files using 'extern' keyword
extern int externalVariable;

// Function prototypes
void demonstrateLocalVariable();
void demonstrateStaticVariable();

int main() {
    // Local variable: Accessible only within the 'main' function
    int localVariable = 10;

    printf("Global variable at the start: %d\n", globalVariable);

    // Modify the global variable
    globalVariable = 200;
    printf("Global variable after modification: %d\n", globalVariable);

    // Demonstrate local variable
    demonstrateLocalVariable();
    demonstrateLocalVariable();

    // Demonstrate static variable
    demonstrateStaticVariable();
    demonstrateStaticVariable();

    return 0;
}

void demonstrateLocalVariable() {
    // Local variable: Gets created and destroyed every time function is called
    int localVar = 0;
    localVar++;
    printf("Local variable: %d\n", localVar);
}

void demonstrateStaticVariable() {
    // Static variable: Retains its value between function calls
    static int staticVar = 0;
    staticVar++;
    printf("Static variable: %d\n", staticVar);
}

