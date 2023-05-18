#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"
#include "sile.h"
#include "Flie.h"

static size_t size_i;
//연산자 오버로딩

int main() {
    
    char* line1 = NULL;
    char* line3 = NULL;

    char*bu=FILE_C();

    
    printf("\n");
    printf("%s", bu);
    printf("\n===================================================================================");           
    
    extractLines(bu,line1,line3);
    
    free(bu);
    return 0;
}
