#include <stdio.h>

int my_strcmp(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 < *s2) {
            return -1;
        } else if (*s1 > *s2) {
            return 1;
        }
        s1++;
        s2++;
    }

    if (*s1 != '\0') {
        return 1;
    }

    if (*s2 != '\0') {
        return -1;
    }

    return 0;
}

int main() {
    char str1[] = "hello";
    char str2[] = "world";
    char str3[] = "hello";

    // Test the my_strcmp function
    printf("Comparing %s and %s: %d\n", str1, str2, my_strcmp(str1, str2));  // Output should be -1
    printf("Comparing %s and %s: %d\n", str2, str1, my_strcmp(str2, str1));  // Output should be 1
    printf("Comparing %s and %s: %d\n", str1, str3, my_strcmp(str1, str3));  // Output should be 0

    return 0;
}

