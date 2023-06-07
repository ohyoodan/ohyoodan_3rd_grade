#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <thread>

const int BUFFER_WIDTH = 80;
const int BUFFER_HEIGHT = 25;
const int BUFFER_DEPTH = 10;  // ºø¿« ±Ì¿Ã (z√‡)

struct Cell {
    char character;
    int zIndex;
};

Cell buffer1[BUFFER_DEPTH][BUFFER_HEIGHT][BUFFER_WIDTH];
Cell buffer2[BUFFER_DEPTH][BUFFER_HEIGHT][BUFFER_WIDTH];

Cell(*currentBuffer)[BUFFER_HEIGHT][BUFFER_WIDTH] = buffer1;
Cell(*nextBuffer)[BUFFER_HEIGHT][BUFFER_WIDTH] = buffer2;

int playerX = 5;
int playerY = BUFFER_HEIGHT - 2;
int playerZ = 0;

int obstacleX = BUFFER_WIDTH - 5;
int obstacleY = BUFFER_HEIGHT - 2;
int obstacleZ = 0;

bool isGameOver = false;
bool isJumping = false;

void Render() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD topLeft = { 0, 0 };
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(consoleHandle, &consoleInfo);
    COORD bufferSize = { BUFFER_WIDTH, BUFFER_HEIGHT };
    SMALL_RECT consoleWriteArea = { 0, 0, BUFFER_WIDTH - 1, BUFFER_HEIGHT - 1 };

    CHAR_INFO consoleBuffer[BUFFER_HEIGHT][BUFFER_WIDTH];
    for (int y = 0; y < BUFFER_HEIGHT; ++y) {
        for (int x = 0; x < BUFFER_WIDTH; ++x) {
            consoleBuffer[y][x].Char.UnicodeChar = currentBuffer[playerZ][y][x].character;
            consoleBuffer[y][x].Attributes = consoleInfo.wAttributes;
        }
    }

    WriteConsoleOutput(consoleHandle, (CHAR_INFO*)consoleBuffer, bufferSize, topLeft, &consoleWriteArea);
}

void UpdateBuffer() {
    for (int z = 0; z < BUFFER_DEPTH; ++z) {
        for (int y = 0; y < BUFFER_HEIGHT; ++y) {
            for (int x = 0; x < BUFFER_WIDTH; ++x) {
                currentBuffer[z][y][x].character = ' ';
            }
        }
    }

    // Draw player
    currentBuffer[playerZ][playerY][playerX].character = '@';

    // Draw obstacle
    currentBuffer[obstacleZ][obstacleY][obstacleX].character = 'O';
}

void SwapBuffers() {
    std::swap(currentBuffer, nextBuffer);
}

void SetConsoleWindowSize(int columns, int rows) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT windowRect;
    windowRect.Left = 0;
    windowRect.Top = 0;
    windowRect.Right = columns - 1;
    windowRect.Bottom = rows - 1;

    COORD bufferSize;
    bufferSize.X = columns;
    bufferSize.Y = rows;

    SetConsoleWindowInfo(consoleHandle, TRUE, &windowRect);
    SetConsoleScreenBufferSize(consoleHandle, bufferSize);
}

void SetCursorVisible(bool visible) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cInfo;
    GetConsoleCursorInfo(consoleHandle, &cInfo);
    cInfo.bVisible = visible;
    SetConsoleCursorInfo(consoleHandle, &cInfo);
}

void InputThread() {
    while (!isGameOver) {
        if (_kbhit()) {
            char key = _getch();

            if (key == 'w' && !isJumping) {
                isJumping = true;
                playerY -= 2;
                Sleep(200);
                playerY += 2;
                isJumping = false;
            }
        }
    }
}

bool CheckCollision(int x1, int y1, int z1, int x2, int y2, int z2) {
    return (x1 == x2 && y1 == y2 && z1 == z2);
}

int main() {
    SetConsoleWindowSize(BUFFER_WIDTH, BUFFER_HEIGHT);
    SetCursorVisible(false);

    std::thread inputThread(InputThread);
    inputThread.detach();

    while (!isGameOver) {
        UpdateBuffer();
        Render();
        SwapBuffers();

        // Move obstacle
        obstacleX--;
        if (obstacleX < 0) {
            obstacleX = BUFFER_WIDTH - 1;
        }

        // Check collision
        if (CheckCollision(playerX, playerY, playerZ, obstacleX, obstacleY, obstacleZ)) {
            isGameOver = true;
        }

        Sleep(100);
    }

    system("cls");
    std::cout << "Game Over!" << std::endl;

    return 0;
}
