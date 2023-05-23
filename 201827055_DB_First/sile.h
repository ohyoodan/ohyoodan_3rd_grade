
#ifndef EXAMPLE_H2
#define EXAMPLE_H2
void splitString(const char* input,char dem, char** front, char** back) {
    int spaceIndex = 0; // 띄어쓰기 인덱스
    int length = strlen(input); // 입력 문자열의 길이

    // 띄어쓰기 위치 찾기
    for (int i = 0; i < length; i++) {
        if (input[i] == dem) {
            spaceIndex = i;
            break;
        }
    }

    // 앞부분 저장
    *front = (char*)malloc((spaceIndex + 1) * sizeof(char));
    strncpy(*front, input, spaceIndex);
    (*front)[spaceIndex] = '\0';

    // 뒷부분 저장
    *back = (char*)malloc((length - spaceIndex) * sizeof(char));
    strcpy(*back, input + spaceIndex + 1);
}


#endif
