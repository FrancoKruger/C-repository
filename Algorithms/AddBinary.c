#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to add binary numbers as integers
int addBinaryInt(int a, int b) {
    int carry;

    while (b != 0) {
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }

    return a;
}

// Function to convert a binary string to an integer
int binaryStringToInt(char *binaryString) {
    int length = strlen(binaryString);
    int value = 0;

    for (int i = 0; i < length; ++i) {
        value <<= 1;
        if (binaryString[i] == '1') {
            value += 1;
        }
    }

    return value;
}

// Function to add binary numbers as strings
char* addBinaryString(char *a, char *b) {
    int intA = binaryStringToInt(a);
    int intB = binaryStringToInt(b);
    int sum = addBinaryInt(intA, intB);

    // Calculate length of the resulting binary string
    int length = 0;
    int tempSum = sum;
    do {
        length++;
        tempSum >>= 1;
    } while (tempSum > 0);

    // Allocate memory for the resulting binary string
    char *result = (char *)malloc(length + 1);

    // Create the resulting binary string
    result[length] = '\0';
    for (int i = length - 1; i >= 0; --i) {
        result[i] = (sum & 1) ? '1' : '0';
        sum >>= 1;
    }

    return result;
}

int main() {
    int a = 5;  // In binary: 0101
    int b = 3;  // In binary: 0011

    int sumInt = addBinaryInt(a, b);
    printf("Sum as integers is %d\n", sumInt);  // Output should be 8 (In binary: 1000)

    char *binA = "101";
    char *binB = "11";
    char *sumStr = addBinaryString(binA, binB);
    printf("Sum as strings is %s\n", sumStr);  // Output should be 1000

    free(sumStr);

    return 0;
}

