#include <stdio.h>

// Define a union type named 'Value'
union Value {
    int i;
    float f;
    char str[20];
};

int main() {
    union Value value;

    // Using the 'i' member of the union
    value.i = 10;
    printf("Integer: %d\n", value.i);

    // Using the 'f' member of the union
    value.f = 20.5;
    printf("Float: %.2f\n", value.f);

    // Using the 'str' member of the union
    snprintf(value.str, sizeof(value.str), "Hello");
    printf("String: %s\n", value.str);

    // Note: The value of 'i' and 'f' are now corrupted
    // because we've used the same memory space for 'str'.
    printf("Corrupted Integer: %d\n", value.i);
    printf("Corrupted Float: %.2f\n", value.f);

    return 0;
}

