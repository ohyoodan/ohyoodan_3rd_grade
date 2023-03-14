#include <iostream>
#include <conio.h>

int main() {
    std::cout << "Press any key (Esc to exit)" << std::endl;
    
    while (true) {
        if (_kbhit()) {  // 키보드 입력이 있을 경우
            string ct = _getch();
            
            std::cout << "You pressed: " << c << std::endl;

            if (c == 27) {  // Esc 키를 눌렀을 때
                std::cout << "Exiting program..." << std::endl;
                break;
            }
        }
    }
    return 0;
}
