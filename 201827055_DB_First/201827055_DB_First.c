#define _CRT_SECURE_NO_WARNINGS
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
        printf("%s\n", root->data);
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
    const char* inputString = "내 이름은 멋진 이은석님이고 이번학기 점수는 989999점이고 성적은 A를 받았습니다.";
    const char* delimiter = " ";

    // 문자열을 쪼개어 저장할 배열 선언
    char dataArray[100][100];
    int dataArraySize = 0;

    // strtok 함수를 사용하여 문자열을 쪼개어 배열에 저장
    char* token = strtok((char*)inputString, delimiter);
    while (token != NULL) {
        strcpy(dataArray[dataArraySize], token);
        dataArraySize++;
        token = strtok(NULL, delimiter);
    }

    // 배열에 저장된 데이터를 이진 트리에 삽입
    struct Node* root = NULL;
    for (int i = 0; i < dataArraySize; i++) {
        root = insertNode(root, dataArray[i]);
    }

    // 이진 트리의 데이터를 중위 순회하여 출력
    printf("이진 트리의 중위 순회 결과:\n");
    inorderTraversal(root);

    // 이진 트리의 메모리 해제
    freeTree(root);

    return 0;
}
