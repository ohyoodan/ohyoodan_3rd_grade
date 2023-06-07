#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include<iostream>
#include "MyClass.hpp"
#include <Windows.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

const int BUFFER_WIDTH = 80;
const int BUFFER_HEIGHT = 25;

char buffer1[BUFFER_HEIGHT][BUFFER_WIDTH];
char buffer2[BUFFER_HEIGHT][BUFFER_WIDTH];
//스트럭트로 문자,색상,뒷 배경 넣기 또 z값 비교 후 순서대로 출력
char(*currentBuffer)[BUFFER_WIDTH] = buffer1;
char(*nextBuffer)[BUFFER_WIDTH] = buffer2;

const int targetFPS = 30;
const int frameDelay=1000/30;

void SetConsoleColor(int text,int background);
void Render() {
    DWORD dw;
    COORD topLeft = { 0, 0 };
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', BUFFER_WIDTH * BUFFER_HEIGHT, topLeft, &dw);  

    for (int y = 0; y < BUFFER_HEIGHT; ++y) {
        for (int x = 0; x < BUFFER_WIDTH; ++x) {
            SetConsoleColor(1, 16);
            std::cout << currentBuffer[y][x];
            SetConsoleColor(7, 0);
        }
        std::cout << std::endl;
    }
}

void UpdateBuffer() {
    // 버퍼 갱신 로직을 구현합니다.
    // 예시로 현재 버퍼에 랜덤한 문자를 채우는 로직을 사용합니다.
    for (int y = 0; y < BUFFER_HEIGHT; ++y) {
        for (int x = 0; x < BUFFER_WIDTH; ++x) {
            currentBuffer[y][x] = 'A' + rand() % 26;  // A부터 Z까지 랜덤한 문자
        }
    }
}

void SwapBuffers() {
    std::swap(currentBuffer, nextBuffer);
}

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

    while (true) {
        auto start = std::chrono::high_resolution_clock::now();
        UpdateBuffer();
        Render();
        SwapBuffers();
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        int remainingTIme = frameDelay - elapsedTime.count();
        if (remainingTIme > 0) {
            std::this_thread::sleep_for(std::chrono::microseconds(remainingTIme));
        }
    }
    
    return 0;
    
}
