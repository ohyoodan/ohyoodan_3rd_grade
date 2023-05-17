
#ifndef EXAMPLE_H
#define EXAMPLE_H

char* duplicateString(const char* str) {
    size_t len = strlen(str);
    char* dup_str = (char*)malloc((len + 1) * sizeof(char));
    if (dup_str != NULL) {
        strcpy(dup_str, str);
    }
    return dup_str;
}

void extractLines(const char* str, char** line1, char** line3) {
    char* token = strtok((char*)str, "\n");
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
