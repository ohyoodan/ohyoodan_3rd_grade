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
            printf("파일을 생성 할 수 없습니다.\n");
            return 1;
        }
        printf("파일이 없어 생성하였습니다.\n");
        printf("\n");
        fprintf(fp, "내 이름은 %%s이고 이번학기 점수는 %%d9999점이고 성적은 %%c를 받았습니다.\n");
        fprintf(fp, "\n");
        fprintf(fp, "내 이름은 멋진 이은석님이고 이번학기 점수는 989999점이고 성적은 A를 받았습니다.");
        fputc('\0', fp);
        fclose(fp);
    }
   // fp = fopen(filename, "r");

   // fseek(fp, 0, SEEK_END);//파일 포인터 지정한 위치로
   // File_size = ftell(fp);//파일 포인터 현재 위치
   // rewind(fp);// 파일 포인터 처음으로

   // char* str = (char*)malloc((File_size) * sizeof(char));//포인터 
   // if (str == NULL) {
   //     printf("\n메모리 할당 실패");
   //     fclose(fp);
   //     return -1;
   // }
   // //fread(str, sizeof(char), File_size, fp);
   // int byte;
   // while ((byte = fgetc(fp)) != EOF) {
   //     // byte 변수에 읽어온 데이터 활용
   //     printf("읽은 데이터: %cX\n", byte);
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
        printf("파일을 열 수 없습니다.\n");
        return NULL;
    }

    // 동적 메모리 할당을 위한 변수들
    char* buffer = NULL;
    size_t buffer_size = 0;
    size_t index = 0;
    int ch;

    while ((ch = fgetc(fp)) != EOF) {
        // 동적 메모리 할당
        if (index == buffer_size) {
            buffer_size += 10;  // 적절한 크기로 조정 가능
            buffer = realloc(buffer, buffer_size * sizeof(char));
            if (buffer == NULL) {
                printf("메모리 할당에 실패했습니다.\n");
                fclose(fp);
                return NULL;
            }
        }

        buffer[index++] = ch;
    }

    buffer = realloc(buffer, (index + 1) * sizeof(char));  // 문자열의 끝에 널 문자 추가
    buffer[index] = '\0';

    fclose(fp);
    return buffer;
}

#endif