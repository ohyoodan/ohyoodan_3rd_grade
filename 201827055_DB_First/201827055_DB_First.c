#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[100];
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(const char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, const char* data) {
    if (root == NULL) {
        return createNode(data);
    }

    int cmpResult = strcmp(data, root->data);
    if (cmpResult < 0) {
        root->left = insertNode(root->left, data);
    }
    else if (cmpResult > 0) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s ", root->data);
        inorderTraversal(root->right);
    }
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;

    root = insertNode(root, "Apple");
    root = insertNode(root, "Banana");
    root = insertNode(root, "Cherry");
    root = insertNode(root, "Date");
    root = insertNode(root, "Fig");

    printf("이진 트리의 중위 순회 결과: ");
    inorderTraversal(root);
    printf("\n");

    freeTree(root);

    return 0;
}
