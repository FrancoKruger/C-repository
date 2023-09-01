#include <stdio.h>

int my_binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Compute mid-point of the array

        if (arr[mid] == target) {
            return mid;  // Target found, return its index
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // Target lies to the right of mid
        }
        else {
            right = mid - 1;  // Target lies to the left of mid
        }
    }

    return -1;  // Target not found in the array
}

int main() {
    // Test the my_binary_search function
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = my_binary_search(arr, size, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

