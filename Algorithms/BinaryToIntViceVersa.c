int binaryToInt(char *s) {
    /* 100 = 0*2^0 + 0 * 2^1 + 1*2^2 */
    int pow = strlen(s) - 1, i;
    int num = 0;

    for (i = pow; i >=0; i--) {
        num += ((*s++)-'0') * power(2,i);
    }

    return num;
}

int power(int a, int b) {

    if (b > 0) {
        return pow(a,b-1)*a;
    }

    return 1;

}

char * intToBinary(int x) {
    /* 15: 15%2 = 1; 15/2 = 7; 7%2 = 1; 7/2 = 3; 3%2 = 1; 1%2 = 1; 0 -> stop */
    int size = (int)floor(log2(x)) + 1;
    char * binary = (char *)malloc(size + 1);
    binary[size--] = '\0';
    while (x > 0) {
        binary[size--] = (x%2) + '0';
        x = x/2;
    }

    return binary;

}
