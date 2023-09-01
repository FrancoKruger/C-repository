#include <stdio.h>
#include <math.h>

int main() {
    double radius = 5.0;
    double circumference = 2 * M_PI * radius;
    double area = M_PI * pow(radius, 2);

    printf("For a circle with radius %.2f:\n", radius);
    printf("Circumference = %.2f\n", circumference);
    printf("Area = %.2f\n", area);

    return 0;
}

