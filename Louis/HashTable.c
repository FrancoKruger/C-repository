#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Define a node structure for linked list to handle collisions
struct Node {
    char *key;
    char *value;
    struct Node *next;
};

// Define a hash table
struct HashTable {
    struct Node *table[TABLE_SIZE];
};

// Hash function to determine index
unsigned int hash(char *key) {
    unsigned int hashValue = 0;
    while (*key) {
        hashValue = (hashValue << 5) + *key++;
    }
    return hashValue % TABLE_SIZE;
}

// Insert key-value pair into hash table
void insert(struct HashTable *ht, char *key, char *value) {
    unsigned int idx = hash(key);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = ht->table[idx];
    ht->table[idx] = newNode;
}

// Search for a value by key in hash table
char *search(struct HashTable *ht, char *key) {
    unsigned int idx = hash(key);
    struct Node *node = ht->table[idx];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

// Free hash table
void freeTable(struct HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        struct Node *node = ht->table[i];
        while (node) {
            struct Node *temp = node;
            node = node->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(ht);
}

int main() {
    struct HashTable *ht = (struct HashTable *)malloc(sizeof(struct HashTable));
    memset(ht->table, 0, sizeof(ht->table));

    insert(ht, "name", "John");
    insert(ht, "age", "30");
    insert(ht, "country", "USA");

    printf("name: %s\n", search(ht, "name"));
    printf("age: %s\n", search(ht, "age"));
    printf("country: %s\n", search(ht, "country"));
    
    freeTable(ht);
    return 0;
}

