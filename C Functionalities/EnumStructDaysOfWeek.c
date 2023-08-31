#include <stdio.h>

typedef enum {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
} DayOfWeek;

typedef struct {
    DayOfWeek day;
    int value;
} DayValue;

void printDayValue(DayValue dv) {
    const char *dayNames[] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };
    
    printf("Day: %s, Value: %d\n", dayNames[dv.day], dv.value);
}

int main() {
    DayValue week[7];
    
    // Initialize
    for (int i = 0; i < 7; ++i) {
        week[i].day = (DayOfWeek)i;
        week[i].value = i * 10;
    }

    // Print
    for (int i = 0; i < 7; ++i) {
        printDayValue(week[i]);
    }
    
    return 0;
}

