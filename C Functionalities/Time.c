#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to check if a year is a leap year
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to calculate the number of days between two dates
int days_between_dates(int start_day, int start_month, int start_year, int end_day, int end_month, int end_year) {
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day_count = 0;
    
    while (start_year < end_year || (start_year == end_year && start_month < end_month) || (start_year == end_year && start_month == end_month && start_day < end_day)) {
        day_count++;
        start_day++;
        
        if (start_day > days_in_month[start_month - 1]) {
            start_day = 1;
            start_month++;
        }
        
        if (start_month > 12) {
            start_month = 1;
            start_year++;
            
            // Update February days for leap year
            days_in_month[1] = is_leap_year(start_year) ? 29 : 28;
        }
    }
    return day_count;
}

int main() {
    // Get and display the current time
    time_t raw_time;
    time(&raw_time);
    printf("Current time: %s\n", ctime(&raw_time));

    // Measure CPU time
    clock_t start = clock();
    for (int i = 0; i < 1000000; i++);
    clock_t end = clock();
    double cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Elapsed CPU time: %f seconds\n", cpu_time);

    // Calculate days between two dates
    int start_day = 1, start_month = 1, start_year = 2020;
    int end_day = 29, end_month = 2, end_year = 2020;
    
    int day_count = days_between_dates(start_day, start_month, start_year, end_day, end_month, end_year);
    printf("Days between %d-%d-%d and %d-%d-%d: %d days\n", start_day, start_month, start_year, end_day, end_month, end_year, day_count);

    return 0;
}

