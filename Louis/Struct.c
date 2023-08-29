#include <stdio.h>

// Declare a struct to represent a simple point in a 2D space
struct Point {
    int x;
    int y;
};

// Function to display the coordinates of a Point instance
void displayPoint(struct Point pt) {
    printf("Point coordinates: (%d, %d)\n", pt.x, pt.y);
}

// Function to display the coordinates of a Point through a pointer
void displayPointPtr(struct Point *ptPtr) {
    printf("Point coordinates via pointer: (%d, %d)\n", ptPtr->x, ptPtr->y);
}

int main() {
    // Create an instance of the Point struct and initialize it
    struct Point point1 = {1, 2};
    
    // Create a pointer to a Point struct and point it to point1
    struct Point *pointPtr = &point1;

    // Access members of a struct instance using dot operator (.)
    printf("Using instance (dot operator):\n");
    displayPoint(point1);

    // Access members of a struct via pointer using arrow operator (->)
    printf("Using pointer (arrow operator):\n");
    displayPointPtr(pointPtr);

    return 0;
}

