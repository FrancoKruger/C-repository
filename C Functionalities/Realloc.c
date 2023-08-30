#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ArrayList definition
typedef struct {
    char **data;
    size_t size;
    size_t capacity;
} ArrayList;

// Function prototypes
ArrayList *createArrayList(size_t initialCapacity);
void addString(ArrayList *list, const char *str);
void freeArrayList(ArrayList *list);

int main() {
    ArrayList *list = createArrayList(2); // Initial capacity is set to 2

    addString(list, "Hello");
    addString(list, "World");
    addString(list, "This");
    addString(list, "Is");
    addString(list, "C");

    for (size_t i = 0; i < list->size; i++) {
        printf("%s ", list->data[i]);
    }
    printf("\n");

    freeArrayList(list);

    return 0;
}

// Function implementations
ArrayList *createArrayList(size_t initialCapacity) {
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    list->data = (char **)malloc(initialCapacity * sizeof(char *));
    list->size = 0;
    list->capacity = initialCapacity;
    return list;
}

void addString(ArrayList *list, const char *str) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (char **)realloc(list->data, list->capacity * sizeof(char *));
    }
    list->data[list->size] = strdup(str);
    list->size++;
}

void freeArrayList(ArrayList *list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->data[i]);
    }
    free(list->data);
    free(list);
}

