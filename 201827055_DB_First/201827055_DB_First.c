#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"

static int size_i;

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
        printf("\n");
        fprintf(fp, "내 이름은 %%s이고 이번학기 점수는 %%d9999점이고 성적은 %%c를 받았습니다.\n");//포멧 9999점 인식 못해야됨 즉 아래 98점으로 출력되어야함
        fprintf(fp, "\n");
        fprintf(fp, "내 이름은 멋진 이은석님이고  이번학기 점수는 989999점이고 성적은 A를 받았습니다.");
        fputc('\0', fp);
        fclose(fp);
    }
    fp = fopen(filename, "r");    
    
    fseek(fp, 0, SEEK_END);//파일 포인터 지정한 위치로
    File_size = ftell(fp);//파일 포인터 현재 위치
    rewind(fp);// 파일 포인터 처음으로

    char* str = (char*)malloc((File_size) * sizeof(char));//포인터 
    if(str == NULL) {
        printf("\n메모리 할당 실패");
        fclose(fp);
        return -1;
    }
    fread(str, sizeof(char), File_size, fp);
    
    size_i= (int)File_size;
    fclose(fp);
    return str;
}
void chack(const char *chack) {
    struct Node* root = NULL;
    struct Node* root1 = NULL;
    
    
    int start = 0;//false;

    int len = 0;
    int char_num=0;
    int int_num=0;
    int str_num=0;

    char* token1 = chack;
    char* token2 = strtok(token1, "\n\n");

    
    char* char_ = (char*)malloc((sizeof(char)) * size_i);
    char* int_ = (char*)malloc((sizeof(char)) * size_i);
    /*char* str_ = (char*)malloc((sizeof(char)) * size_i);    */
    
    while (1) {
        root = insertNode(root, chack[len]);
        len++;
        if(start == 0) {
            len = 0;
            start = 1;
        }

        if (chack[len]=='\0') {
            break;
        }
        else if (chack[len] == '%') {
            len++;            
            switch (chack[len])
            {
            case 'd':int_num++;
                len++;
                break;
            case 's':str_num++;
                len++;
                break;
            case 'c':char_num++;
                len++;
                break;
            default:
                break;
            }
        }
        
                
    }

    
    printf("\nint(%d개): %s",int_num,int_);                       

    printf("\nchar(%d개):%s",char_num,char_);

    //pritnf("\nstring(%d개):%s",str_num,str_);


    freeTree(root);
    
    free(int_);    
    
}

int main() {
    
    
    char*bu=FILE_C();
    printf("\n");
    printf("%s", bu);
    printf("\n===================================================================================");
    chack(bu);
    
    
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

    
    free(bu);
    return 0;
}
