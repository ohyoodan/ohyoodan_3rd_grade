#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main() {
	FILE* fp;
	 int ch;
	 char str[] = "asasdasdasdasddsds";
	fp = fopen("a.txt", "w");
	if (fp == NULL) {
		printf("파일이 열리지 않았습니다.");
		return 1;
	}
	printf("파일이 열렷습니다");

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


