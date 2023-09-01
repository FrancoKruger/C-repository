#include <stdio.h>
#include <math.h>

void showcase_math_library() {
    // Initializing variables
    double x = 16.0;
    double y = 9.0;
    double angle = 30.0;  // in degrees
    double radian = angle * M_PI / 180.0;  // Convert to radians

    // Square root
    printf("Square root of %.2f is %.2f\n", x, sqrt(x));

    // Power
    printf("%.2f raised to the power of %.2f is %.2f\n", x, y, pow(x, y));

    // Absolute
    printf("Absolute value of -%.2f is %.2f\n", x, fabs(-x));

    // Trigonometric functions (input is in radians)
    printf("sin(%.2f radians) = %.2f\n", radian, sin(radian));
    printf("cos(%.2f radians) = %.2f\n", radian, cos(radian));
    printf("tan(%.2f radians) = %.2f\n", radian, tan(radian));

    // Inverse Trigonometric functions (output is in radians)
    printf("asin(0.5) in radians = %.2f\n", asin(0.5));
    printf("acos(0.5) in radians = %.2f\n", acos(0.5));
    printf("atan(0.5) in radians = %.2f\n", atan(0.5));

    // Exponential
    printf("Exponential of %.2f is %.2f\n", x, exp(x));

    // Logarithm
    printf("Natural logarithm of %.2f is %.2f\n", x, log(x));
    printf("Base 10 logarithm of %.2f is %.2f\n", x, log10(x));

    // Rounding functions
    printf("Floor value of 2.7 is %.2f\n", floor(2.7));
    printf("Ceil value of 2.3 is %.2f\n", ceil(2.3));
    printf("Round value of 2.7 is %.2f\n", round(2.7));

    // Modulus
    printf("Modulus of %.2f and %.2f is %.2f\n", x, y, fmod(x, y));
}

int main() {
    // Showcase the math library functions
    showcase_math_library();
    return 0;
}

