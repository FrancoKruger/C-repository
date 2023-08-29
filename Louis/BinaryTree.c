#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the binary tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary tree
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

// In-order traversal
void inOrder(struct Node* node) {
    if (node != NULL) {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
}

// Pre-order traversal
void preOrder(struct Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

// Post-order traversal
void postOrder(struct Node* node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ", node->data);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}

