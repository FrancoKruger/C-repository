#include <stdio.h>

// Define an enum named 'Weekday'
enum Weekday {
    Sunday,    // 0
    Monday,    // 1
    Tuesday,   // 2
    Wednesday, // 3
    Thursday,  // 4
    Friday,    // 5
    Saturday   // 6
};

// Function to print the name of the day
void printDay(enum Weekday day) {
    switch (day) {
        case Sunday:
            printf("It's Sunday!\n");
            break;
        case Monday:
            printf("It's Monday!\n");
            break;
        case Tuesday:
            printf("It's Tuesday!\n");
            break;
        case Wednesday:
            printf("It's Wednesday!\n");
            break;
        case Thursday:
            printf("It's Thursday!\n");
            break;
        case Friday:
            printf("It's Friday!\n");
            break;
        case Saturday:
            printf("It's Saturday!\n");
            break;
    }
}

int main() {
    // Declare a variable of type 'enum Weekday'
    enum Weekday today;

    // Initialize the variable
    today = Wednesday;
    
    // Use the enum in a function
    printDay(today);

    // You can also directly use integers to represent enum values
    // In this case, 4 represents Thursday
    printDay(4);
    
    return 0;
}

