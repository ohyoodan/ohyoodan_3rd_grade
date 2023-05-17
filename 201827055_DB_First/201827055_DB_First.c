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
            printf("������ ���� �� �� �����ϴ�.\n");
            return 1;
        }
        printf("������ ���� �����Ͽ����ϴ�.\n");
        printf("\n");
        fprintf(fp, "�� �̸��� %%s�̰� �̹��б� ������ %%d9999���̰� ������ %%c�� �޾ҽ��ϴ�.\n");//���� 9999�� �ν� ���ؾߵ� �� �Ʒ� 98������ ��µǾ����
        fprintf(fp, "\n");
        fprintf(fp, "�� �̸��� ���� ���������̰�  �̹��б� ������ 989999���̰� ������ A�� �޾ҽ��ϴ�.");
        fputc('\0', fp);
        fclose(fp);
    }
    fp = fopen(filename, "r");    
    
    fseek(fp, 0, SEEK_END);//���� ������ ������ ��ġ��
    File_size = ftell(fp);//���� ������ ���� ��ġ
    rewind(fp);// ���� ������ ó������

    char* str = (char*)malloc((File_size) * sizeof(char));//������ 
    if(str == NULL) {
        printf("\n�޸� �Ҵ� ����");
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

    
    printf("\nint(%d��): %s",int_num,int_);                       

    printf("\nchar(%d��):%s",char_num,char_);

    //pritnf("\nstring(%d��):%s",str_num,str_);


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
    /*printf("���� Ʈ���� ���� ��ȸ ���: ");
    inorderTraversal(root);*/
    printf("\n");

    
    free(bu);
    return 0;
}
