#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>  

#include <string.h>  

#include <stdarg.h>  

int yuhanscanf(const char* format, ...) {


	//stdout 출력 스트림  

	//stdin 키보드로부터 입력받는 표준 입력 스트림  

	//stderr   

	va_list args;

	va_start(args, format);

	int match_count = 0;

	char str[512] = { 0, };

	char* input = str;

	fgets(str,511, stdin);

	//char* token = strtok(str, " ");

	while (*format != '\0') {

		if (*format == '%') {

			format++;

			void* arg = va_arg(args, void*);// 다음 매개변수의 void형 주소

			switch (*format) {

			case 'd':

				*(int*)arg = atoi(input);//void포인터를 (int*)로 형변환 후 atoi 결과를 넣음

				match_count++;

				break;

			case 'f':

				*(float*)arg = atof(input);

				match_count++;

				break;

			case 's':

				strcpy((char*)arg, input);

				match_count++;

				break;

			case 'c':

				*(char*)arg = *input;

				match_count++;

				break;

			default:

				break;

			}

		}

		format++;

		while (*input != '\0' && *input != ' ')


		{
			input++;
		}

		if (*str == ' ') {

			input++;

		}

	}
	va_end(args);

	return match_count;

}


int main() {

	char string[512];

	int a = 10;

	float b = 1.2;

	char c = 'a';

	char d[512] = "rr";

	

	yuhanscanf("%d %f %c %s", &a, &b, &c, d);

	printf("TEST\n");

	printf("%d %.2f %c %s", a, b, c, d);

	return 0;



}