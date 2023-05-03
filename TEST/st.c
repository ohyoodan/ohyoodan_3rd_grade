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
    while (token != NULL && *format != '\n') {
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
        }
        format++;
        token = strtok(NULL, " ");
    }
    va_end(args);
    return match_count;
}

int main() {
    int a;
    float b=3.4;
    char c[10] = { 'd',};
    yuhanscanf("%d %f %s", &a, &b, c);
    printf("TEST");
    printf("%d %f %s\n", a, b, c);
    return 0;
}
