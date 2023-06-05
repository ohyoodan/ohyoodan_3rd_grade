#include <Windows.h>
#include<iostream>
#include "MyClass.hpp"

// 콘솔 창의 색상을 변경하는 함수
void SetConsoleColor(int text, int background) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = text + (background * 16);
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    // 예시: 텍스트를 빨간색, 배경을 검정색으로 설정
    SetConsoleColor(12, 0);

    // 색상이 변경된 상태로 출력
    std::cout << "Hello, World!" << std::endl;
    SetConsoleColor(13, 1);
    std::cout << "Hello, World!" << std::endl;
    // 기본 색상으로 복원
    SetConsoleColor(7, 0);


    
    /*0: 검정색
        1 : 파란색
        2 : 초록색
        3 : 청록색
        4 : 빨간색
        5 : 자주색
        6 : 노란색
        7 : 흰색
        8 : 회색
        9 : 밝은 파란색
        10 : 밝은 초록색
        11 : 밝은 청록색
        12 : 밝은 빨간색
        13 : 밝은 자주색
        14 : 밝은 노란색
        15 : 밝은 흰색*/


    MyClass obj;  // MyClass 객체를 선언

    obj.myMethod();  // MyClass 객체의 멤버 함수 호출

    return 0;


    return 0;
}
