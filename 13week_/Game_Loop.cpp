#pragma once
#include<iostream>
#include <vector>//자료형
#include <windows.h>
#include <chrono>// 시간 
#include <thread>// 스레드
#include <fstream>//파일
#include <string>// 문자열
#include"Object.cpp"
#include"Scene.cpp"
using namespace std;
namespace GameEngine {

	class GameLoop {

		const int targetFPS = 30;	
		const int frameDelay = 1000 / targetFPS;
		bool start = false;
		int score = 0;

		enum state {
		Title,
		};

		public: GameLoop() {

		}
		public:~GameLoop() {

		}

		void start_L() {
			init();

			while (1) {
				auto start = std::chrono::high_resolution_clock::now();
				Input();
				Update();
				Render();
				auto end = std::chrono::high_resolution_clock::now();
				auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
				int remainingTIme = frameDelay - elapsedTime.count();
				if (remainingTIme > 0) {
					std::this_thread::sleep_for(std::chrono::microseconds(remainingTIme));
				}
			}

		}

		void init() {
			
			

		}

		void Update() {


		}

		void Render() {
			
		}
		
		void Input() {

		}


	};


}