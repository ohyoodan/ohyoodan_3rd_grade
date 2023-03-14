#include <iostream>
#include <conio.h>

int main() {
    std::cout << "Press Esc to exit the program" << std::endl;

    while (true) {
        if (_kbhit()) {  // 키보드 입력이 있을 경우
            char c = _getch();
            if (c == 27) {  // Esc 키를 눌렀을 때
                std::cout << "Exiting program..." << std::endl;
                break;
            }
        }
    }
    return 0;
}
