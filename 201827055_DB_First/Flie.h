#ifndef EXAMPLE_H3
#define EXAMPLE_H3

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
        fprintf(fp, "�� �̸��� %%s�̰� �̹��б� ������ %%d9999���̰� ������ %%c�� �޾ҽ��ϴ�.\n");
        fprintf(fp, "\n");
        fprintf(fp, "�� �̸��� ���� ���������̰� �̹��б� ������ 989999���̰� ������ A�� �޾ҽ��ϴ�.");
        fputc('\0', fp);
        fclose(fp);
    }
    fp = fopen(filename, "r");

    fseek(fp, 0, SEEK_END);//���� ������ ������ ��ġ��
    File_size = ftell(fp);//���� ������ ���� ��ġ
    rewind(fp);// ���� ������ ó������

    char* str = (char*)malloc((File_size) * sizeof(char));//������ 
    if (str == NULL) {
        printf("\n�޸� �Ҵ� ����");
        fclose(fp);
        return -1;
    }
    //fread(str, sizeof(char), File_size, fp);
    fgets(str,  File_size, fp);
    fgets(str + strlen(str), File_size-strlen(str), fp);
    fgets(str + strlen(str), File_size - strlen(str), fp);
    
    fclose(fp);

    return str;
}
#endif