int reverse(int x){
    int negative = x < 0;
    

    if (negative) {
        if (x * -1 -INT_MAX > 0) {
            return 0;
        }
        x *= -1;
    }
    int size = totalDigits(x), i;
    int new, total = 0;

    for (i = 0; i < size; i++) {
        new = x%10;
        if (total + new*pow(10, size-1-i) - INT_MAX > 0) {
            return 0;
        }
        total += new * pow(10,size-1-i);
        x = x/10;
    }
    if (negative) {
        total *= -1;
    }
    return total;

}

int totalDigits(int x) {
    if (x > 0) {
        return 1 + totalDigits(x/10);
    }

    return 0;
}
