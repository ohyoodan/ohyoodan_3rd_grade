#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"
#include "sile.h"
#include "Flie.h"



//연산자 오버로딩

int main() {
    
    char* line1 = NULL;
    char* line3 = NULL;
    char str_dem = '\n';
    char* bu;
    FILE_C();
    bu = readFromFile();
    size_t size_ =sizeof(bu);
    
    printf("\n");
    printf("%s", bu);
    printf("\n===================================================================================\n");           
    
    splitString(bu,str_dem,&line1,&line3);
    
    printf("%s",line1);
    printf("%s",line3);

    char line_1[256];
    char line_3[256];

    strcpy(line_1, line1);
    strcpy(line_3, line3);
    free(line1);
    free(line3);
    struct Node* root = NULL;

    root = insertNode(root, line_1);
    root = insertNode(root, line_3);

    inorderTraversal(root);

    free(bu);
    return 0;
}
