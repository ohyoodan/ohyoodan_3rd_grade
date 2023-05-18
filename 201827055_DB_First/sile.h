
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
        *line1 = duplicateString(token); // 첫 번째 줄 복제

        token = strtok(NULL, "\n"); // 두 번째 줄은 필요하지 않으므로 건너뜁니다

        token = strtok(NULL, "\n"); // 세 번째 줄 복제
        if (token != NULL) {
            *line3 = duplicateString(token);
        }
    }
}
#endif
