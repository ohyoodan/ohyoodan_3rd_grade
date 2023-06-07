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
//��Ʈ��Ʈ�� ����,����,�� ��� �ֱ� �� z�� �� �� ������� ���
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
    // ���� ���� ������ �����մϴ�.
    // ���÷� ���� ���ۿ� ������ ���ڸ� ä��� ������ ����մϴ�.
    for (int y = 0; y < BUFFER_HEIGHT; ++y) {
        for (int x = 0; x < BUFFER_WIDTH; ++x) {
            currentBuffer[y][x] = 'A' + rand() % 26;  // A���� Z���� ������ ����
        }
    }
}

void SwapBuffers() {
    std::swap(currentBuffer, nextBuffer);
}

// �ܼ� â�� ������ �����ϴ� �Լ�
void SetConsoleColor(int text, int background) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = text + (background * 16);
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    // ����: �ؽ�Ʈ�� ������, ����� ���������� ����
    SetConsoleColor(12, 0);

    // ������ ����� ���·� ���
    std::cout << "Hello, World!" << std::endl;
    SetConsoleColor(13, 1);
    std::cout << "Hello, World!" << std::endl;
    // �⺻ �������� ����
    SetConsoleColor(7, 0);


    
    /*0: ������
        1 : �Ķ���
        2 : �ʷϻ�
        3 : û�ϻ�
        4 : ������
        5 : ���ֻ�
        6 : �����
        7 : ���
        8 : ȸ��
        9 : ���� �Ķ���
        10 : ���� �ʷϻ�
        11 : ���� û�ϻ�
        12 : ���� ������
        13 : ���� ���ֻ�
        14 : ���� �����
        15 : ���� ���*/


    MyClass obj;  // MyClass ��ü�� ����

    obj.myMethod();  // MyClass ��ü�� ��� �Լ� ȣ��

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
