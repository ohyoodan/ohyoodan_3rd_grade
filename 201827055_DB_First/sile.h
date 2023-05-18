
#ifndef EXAMPLE_H2
#define EXAMPLE_H2

char* duplicateString(const char* str1) {
    size_t len = strlen(str1);
    char* dup_str = (char*)malloc((len + 1) * sizeof(char));
    if (dup_str != NULL) {
        strcpy(dup_str, str1);
    }
    return dup_str;
}

void extractLines(const char* str1, char** line1, char** line3) {
    char* token = strtok((char*)str1, "\n\n");
    if (token != NULL) {
        *line1 = duplicateString(token); // ù ��° �� ����

        token = strtok(NULL, "\n"); // �� ��° ���� �ʿ����� �����Ƿ� �ǳʶݴϴ�

        token = strtok(NULL, "\n"); // �� ��° �� ����
        if (token != NULL) {
            *line3 = duplicateString(token);
        }
    }
}
#endif
