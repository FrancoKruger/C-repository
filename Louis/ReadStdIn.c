#include <stdio.h>

int main() {
    int intInput;
    float floatInput;
    char strInput[50];
    
    // Reading an integer
    printf("Enter an integer: ");
    scanf("%d", &intInput);
    
    // Reading a floating-point number
    printf("Enter a float: ");
    scanf("%f", &floatInput);
    
    // Reading a string
    printf("Enter a string: ");
    scanf("%s", strInput);
    
    // Displaying the entered values
    printf("You entered the integer: %d\n", intInput);
    printf("You entered the float: %f\n", floatInput);
    printf("You entered the string: %s\n", strInput);

    return 0;
}

