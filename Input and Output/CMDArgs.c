#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(int a, int b) {
    printf("Sum: %d\n", a + b);
}

void subtract(int a, int b) {
    printf("Difference: %d\n", a - b);
}

void greet(char *name) {
    printf("Hello, %s!\n", name);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <operation> <arguments>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "add") == 0) {
        if (argc != 4) {
            printf("Usage: %s add <num1> <num2>\n", argv[0]);
            return 1;
        }
        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
        add(a, b);
    } else if (strcmp(argv[1], "subtract") == 0) {
        if (argc != 4) {
            printf("Usage: %s subtract <num1> <num2>\n", argv[0]);
            return 1;
        }
        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
        subtract(a, b);
    } else if (strcmp(argv[1], "greet") == 0) {
        if (argc != 3) {
            printf("Usage: %s greet <name>\n", argv[0]);
            return 1;
        }
        greet(argv[2]);
    } else {
        printf("Invalid operation.\n");
        return 1;
    }

    return 0;
}

