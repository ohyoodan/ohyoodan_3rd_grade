#include <Windows.h>
#include<iostream>
#include "MyClass.hpp"

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

    return 0;


    return 0;
}
