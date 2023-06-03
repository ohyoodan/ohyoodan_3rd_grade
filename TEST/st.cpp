#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

int main() {
    const int targetFPS = 30;
    const int frameDelay = 1000 / targetFPS;

    while (true) {
        auto start = std::chrono::high_resolution_clock::now();

        // FPS 제한을 적용할 로직 수행
        // ...

        auto end = std::chrono::high_resolution_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        int remainingTime = frameDelay - elapsedTime.count();
        if (remainingTime > 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(remainingTime));
        }
    }

    return 0;
}
