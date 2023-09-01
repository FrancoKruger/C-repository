#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Binary to Decimal
int BtoD(const char *binary) {
    int decimal = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; ++i) {
        if (binary[i] == '1') {
            decimal += pow(2, length - i - 1);
        } else if (binary[i] != '0') {
            return -1;  // Invalid binary input
        }
    }
    return decimal;
}

// Decimal to Binary
char *DtoB(int decimal) {
    char *binary = malloc(33);  // 32 bits + null terminator
    int i;
    for (i = 31; i >= 0; --i) {
        binary[31 - i] = (decimal & (1 << i)) ? '1' : '0';
    }
    binary[32] = '\0';
    return binary;
}

// Hexadecimal to Binary
char *HtoB(const char *hex) {
    char *binary = malloc(strlen(hex) * 4 + 1);  // 4 bits per hex digit
    binary[0] = '\0';
    for (int i = 0; i < strlen(hex); ++i) {
        switch (hex[i]) {
            case '0': strcat(binary, "0000"); break;
            case '1': strcat(binary, "0001"); break;
            case '2': strcat(binary, "0010"); break;
            case '3': strcat(binary, "0011"); break;
            case '4': strcat(binary, "0100"); break;
            case '5': strcat(binary, "0101"); break;
            case '6': strcat(binary, "0110"); break;
            case '7': strcat(binary, "0111"); break;
            case '8': strcat(binary, "1000"); break;
            case '9': strcat(binary, "1001"); break;
            case 'A': case 'a': strcat(binary, "1010"); break;
            case 'B': case 'b': strcat(binary, "1011"); break;
            case 'C': case 'c': strcat(binary, "1100"); break;
            case 'D': case 'd': strcat(binary, "1101"); break;
            case 'E': case 'e': strcat(binary, "1110"); break;
            case 'F': case 'f': strcat(binary, "1111"); break;
            default: return NULL;  // Invalid hex input
        }
    }
    return binary;
}

// Binary to Hexadecimal
char *BtoH(const char *binary) {
    char *hex = malloc(strlen(binary) / 4 + 1);
    int index = 0;
    for (int i = strlen(binary) % 4; i < strlen(binary); i += 4) {
        char temp[5] = {0};
        strncpy(temp, binary + i, 4);
        int value = BtoD(temp);
        if (value < 10) hex[index++] = '0' + value;
        else hex[index++] = 'A' + (value - 10);
    }
    hex[index] = '\0';
    return hex;
}

// Hexadecimal to Decimal
int HtoD(const char *hex) {
    return BtoD(HtoB(hex));
}

// Decimal to Hexadecimal
char *DtoH(int decimal) {
    return BtoH(DtoB(decimal));
}

int main() {
    // Test the conversion functions
    printf("BtoD(\"1101\") = %d\n", BtoD("1101"));
    printf("DtoB(13) = %s\n", DtoB(13));
    printf("HtoB(\"1D\") = %s\n", HtoB("1D"));
    printf("BtoH(\"00011101\") = %s\n", BtoH("00011101"));
    printf("HtoD(\"1D\") = %d\n", HtoD("1D"));
    printf("DtoH(29) = %s\n", DtoH(29));

    return 0;
}

