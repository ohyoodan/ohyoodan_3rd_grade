#define _CRT_SECURE_NO_WARNINGS

#include <iostream> 

#include <string> 

#include <stdio.h> 

//include<limits> 리미트  사용해 예외처리 

int main()

{

    unsigned short a[5];

    unsigned short b[5];

    for (int i = 0; i < 5; i++) {

        int te = 0;

        scanf("%d", &te);

        a[i] = (short)te;

    }

    for (int i = 0; i < 5; i++) {

        printf("%d ", a[i]);

    }

    int ass = 4;

    printf("\n");

    for (int i = 0; i < 5; i++) {

        short abc;

        abc = a[ass - i];

        b[i] = abc;



    }

    for (int i = 0; i < 5; i++) {

        printf("%d ", b[i]);

    }



    return 0;

}