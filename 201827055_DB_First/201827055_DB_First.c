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
        printf(fp, "\n");
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
    
    int len = 0;
    while (1) {
        if (len==size_i) {
            
        }
        else if (chack[len + 1] == '\0') {
            break;
        }
        printf("\n%d\n",len);
        len++;
    }

}

int main() {
    struct Node* root = NULL;
    
    char*bu=FILE_C();
    printf("\n");
    printf("%s", bu);
    
    chack(bu);
    
    // free(bu);
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

    //freeTree(root);

    return 0;
}
