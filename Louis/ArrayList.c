#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} ArrayList;

// Initialize ArrayList
ArrayList* initArrayList(size_t initialCapacity) {
    ArrayList *list = malloc(sizeof(ArrayList));
    if (list == NULL) {
        printf("Memory allocation failed for ArrayList.\n");
        exit(1);
    }
    list->data = malloc(initialCapacity * sizeof(int));
    list->size = 0;
    list->capacity = initialCapacity;
    return list;
}

// Add element to ArrayList
void add(ArrayList *list, int element) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        int *newData = realloc(list->data, list->capacity * sizeof(int));
        if (newData == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
        list->data = newData;
    }
    list->data[list->size++] = element;
}

// Display ArrayList
void display(ArrayList *list) {
    printf("[ ");
    for (size_t i = 0; i < list->size; ++i) {
        printf("%d ", list->data[i]);
    }
    printf("]\n");
}

// Free ArrayList
void freeArrayList(ArrayList *list) {
    free(list->data);
    free(list);
}

int main() {
    ArrayList *list = initArrayList(2);
    
    add(list, 1);
    add(list, 2);
    add(list, 3);
    
    printf("ArrayList contents: ");
    display(list);

    printf("ArrayList size: %zu\n", list->size);
    printf("ArrayList capacity: %zu\n", list->capacity);
    
    freeArrayList(list);
    
    return 0;
}

