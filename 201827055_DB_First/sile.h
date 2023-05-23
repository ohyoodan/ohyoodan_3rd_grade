
#ifndef EXAMPLE_H2
#define EXAMPLE_H2
void splitString(const char* input,char dem, char** front, char** back) {
    int spaceIndex = 0; // ���� �ε���
    int length = strlen(input); // �Է� ���ڿ��� ����

    // ���� ��ġ ã��
    for (int i = 0; i < length; i++) {
        if (input[i] == dem) {
            spaceIndex = i;
            break;
        }
    }

    // �պκ� ����
    *front = (char*)malloc((spaceIndex + 1) * sizeof(char));
    strncpy(*front, input, spaceIndex);
    (*front)[spaceIndex] = '\0';

    // �޺κ� ����
    *back = (char*)malloc((length - spaceIndex) * sizeof(char));
    strcpy(*back, input + spaceIndex + 1);
}


#endif
