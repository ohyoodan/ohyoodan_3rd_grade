#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main() {
	FILE* fp;
	 int ch;
	 char str[] = "asasdasdasdasddsds";
	fp = fopen("a.txt", "w");
	if (fp == NULL) {
		printf("������ ������ �ʾҽ��ϴ�.");
		return 1;
	}
	printf("������ ���ǽ��ϴ�");

	//while (1) {
	//	ch = fgetc(fp);
	//	if (ch == EOF) {
	//		break;

	//	}
	//	putchar(ch);
	//}
	int i;
	i = 0;
	while (str[i] != '\0') {
		fputc(str[i], fp);
		i++;

	}
	fputc('\n', fp);
	fclose(fp);

	return 0;
}


