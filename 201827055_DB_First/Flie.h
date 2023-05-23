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
   
    fclose(fp);    
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
        if (index == buffer_size) {
            buffer_size += 10;  // �ʿ��� ��ŭ ũ�⸦ ������ �� �ֽ��ϴ�.
            char* new_buffer = (char*)realloc(buffer, buffer_size * sizeof(char));
            if (new_buffer == NULL) {
                printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
                fclose(fp);
                return NULL;
            }
            buffer = new_buffer;
        }

        buffer[index++] = ch;
    }

    buffer = (char*)realloc(buffer, (index + 1) * sizeof(char));  // ���ڿ��� ���� �� ���� �߰�
    buffer[index] = '\0';

    fclose(fp);
    return buffer;
}

#endif