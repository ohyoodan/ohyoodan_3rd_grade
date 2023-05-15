
#ifndef EXAMPLE_H
#define EXAMPLE_H
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
#endif