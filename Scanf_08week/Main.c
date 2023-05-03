#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>  

#include <string.h>  

#include <stdarg.h>  

int yuhanscanf(const char* format, ...) {


	//stdout ��� ��Ʈ��  

	//stdin Ű����κ��� �Է¹޴� ǥ�� �Է� ��Ʈ��  

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

			void* arg = va_arg(args, void*);// ���� �Ű������� void�� �ּ�

			switch (*format) {

			case 'd':

				*(int*)arg = atoi(input);//void�����͸� (int*)�� ����ȯ �� atoi ����� ����

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