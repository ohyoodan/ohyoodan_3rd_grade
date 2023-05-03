#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>  
int yuhanscanf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    int match_count = 0;
    char str[512];
    fgets(str, sizeof(str), stdin);
    char* token = strtok(str, " ");

    while (token != NULL && *format != '\n') {//다음 토큰이 없을 때, 다음 포멧이 없을 때

        if (*format == '%') {
            format++;
            void* arg = va_arg(args, void*);
            switch (*format) {
            case 'd':
                *(int*)arg = atoi(token);
                match_count++;
                break;
            case 'f':
                *(float*)arg = atof(token);
                match_count++;
                break;
            case 's':
                strcpy((char*)arg, token);
                match_count++;
                break;
            case 'c':
                *(char*)arg = *token;
                match_count++;
                break;
            default:
                break;
            }
            token = strtok(NULL, " ");
        }
        format++;// 끝날 때 한 번씩 




    }
    va_end(args);
    return match_count;
}

int main() {
    int a;
    float b = 3.4;
    char c;
    char d[10];

    int t;
    t = yuhanscanf("%d %f %c %s", &a, &b, &c, d);
    printf("%d\n", t);
    printf("%d %f %c %s \n", a, b, c, d);
    return 0;
}
