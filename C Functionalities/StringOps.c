#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char str1[] = "Hello, ";
    char str2[] = "World!";
    char buffer[50];

    // String concatenation
    strcat(str1, str2);
    printf("Concatenated String: %s\n", str1);

    // String length
    printf("Length of string: %lu\n", strlen(str1));

    // String copy
    strcpy(buffer, str1);
    printf("Copied string: %s\n", buffer);

    // Substring search
    if (strstr(str1, "World")) {
        printf("Substring 'World' found!\n");
    }

    // Character search
    if (strchr(str1, '!')) {
        printf("Character '!' found!\n");
    }

    // String comparison
    if (strcmp(str1, buffer) == 0) {
        printf("Both strings are equal.\n");
    }

    // Convert to uppercase
    toUpperCase(buffer);
    printf("Uppercase conversion: %s\n", buffer);

    // Convert to lowercase
    toLowerCase(buffer);
    printf("Lowercase conversion: %s\n", buffer);

    // String reversal (not in string.h but commonly used)
    strrev(buffer);
    printf("Reversed string: %s\n", buffer);

    return 0;
}

