#ifndef EXAMPLE_H3
#define EXAMPLE_H3

void FILE_C() {
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
        fprintf(fp, "�� �̸��� %%s�̰� �̹��б� ������ %%d9999���̰� ������ %%c�� �޾ҽ��ϴ�.\n");
        fprintf(fp, "\n");
        fprintf(fp, "�� �̸��� ���� ���������̰� �̹��б� ������ 989999���̰� ������ A�� �޾ҽ��ϴ�.");
        fputc('\0', fp);
        fclose(fp);
    }
   // fp = fopen(filename, "r");

   // fseek(fp, 0, SEEK_END);//���� ������ ������ ��ġ��
   // File_size = ftell(fp);//���� ������ ���� ��ġ
   // rewind(fp);// ���� ������ ó������

   // char* str = (char*)malloc((File_size) * sizeof(char));//������ 
   // if (str == NULL) {
   //     printf("\n�޸� �Ҵ� ����");
   //     fclose(fp);
   //     return -1;
   // }
   // //fread(str, sizeof(char), File_size, fp);
   // int byte;
   // while ((byte = fgetc(fp)) != EOF) {
   //     // byte ������ �о�� ������ Ȱ��
   //     printf("���� ������: %cX\n", byte);
   // }
   ///* fgets(str,  File_size, fp);
   // fgets(str + strlen(str), File_size -strlen(str), fp);
   // fgets(str + strlen(str), File_size - strlen(str), fp);
   // */
    fclose(fp);

    //return str;
}
char* readFromFile() {
    FILE* fp = fopen("TEST.txt", "r");
    if (fp == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return NULL;
    }

    // ���� �޸� �Ҵ��� ���� ������
    char* buffer = NULL;
    size_t buffer_size = 0;
    size_t index = 0;
    int ch;

    while ((ch = fgetc(fp)) != EOF) {
        // ���� �޸� �Ҵ�
        if (index == buffer_size) {
            buffer_size += 10;  // ������ ũ��� ���� ����
            buffer = realloc(buffer, buffer_size * sizeof(char));
            if (buffer == NULL) {
                printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
                fclose(fp);
                return NULL;
            }
        }

        buffer[index++] = ch;
    }

    buffer = realloc(buffer, (index + 1) * sizeof(char));  // ���ڿ��� ���� �� ���� �߰�
    buffer[index] = '\0';

    fclose(fp);
    return buffer;
}

#endif