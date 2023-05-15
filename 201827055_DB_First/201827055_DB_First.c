#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"

char* FILE_C() {
    FILE* fp;
    long File_size;
    char filename[] = "TEST.txt";
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fp = fopen(filename, "w");
        if (fp == NULL) {
            printf("파일을 생성 할 수 없습니다.\n");
            return 1;
        }
        printf("파일이 없어 생성하였습니다.\n");
        printf(fp, "\n");
        fprintf(fp, "내 이름은 %%s이고 이번학기 점수는 %%d9999점이고 성적은 %%c를 받았습니다.\n");//포멧 9999점 인식 못해야됨 즉 아래 98점으로 출력되어야함
        fprintf(fp, "\n");
        fprintf(fp, "내 이름은 멋진 이은석님이고  이번학기 점수는 989999점이고 성적은 A를 받았습니다.\n\0");
        fclose(fp);
    }
    fp = fopen(filename, "r");
    char buffer[256];
    
    while (fgets(buffer, sizeof(buffer), fp )!= NULL) {
        printf("%s", buffer);        
    }
    fseek(fp, 0, SEEK_END);//파일 크기 계산
    File_size = ftell(fp);
    rewind(fp);

    char* str = (char*)malloc(File_size * sizeof(char));
    if (str == NULL) {
        printf("\n메모리 할당 실패");
        fclose(fp);
        return -1;
    }
    fread(str, sizeof(char), File_size, fp);
    str[File_size] = '\0';

    fclose(fp);
    return str;
}


int main() {
    struct Node* root = NULL;
    
    char*bu=FILE_C();
    printf("\n");
    printf("%s", bu);
   // free(bu);
   /* root = insertNode(root, "Apple");
    root = insertNode(root, "Banana");
    root = insertNode(root, "Cherry");
    root = insertNode(root, "Date");
    root = insertNode(root, "Fig");
    */


    printf("\n");
    /*printf("이진 트리의 중위 순회 결과: ");
    inorderTraversal(root);*/
    printf("\n");

    //freeTree(root);

    return 0;
}
