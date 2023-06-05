
#include "Game_Loop.h"

using namespace std;
namespace GameEngine {
	class Scene;

	class Object;

	
		GameLoop::GameLoop(): targetFPS(30),frameDelay(1000 / targetFPS){
			score = 0;
			Gamestate = Title;
			start = false;
			
		}
		GameLoop::~GameLoop() {

		}

		void GameLoop::start_L(){
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

		void GameLoop::init() {
			
			SceneCreate(Gamestate);

		}

		void GameLoop::SceneCreate(state state) {

			switch(state) {
			case Title: viewScene = new GameEngine::Title(); break;


			}
			
		}

		void GameLoop::Update() {


		}

		void GameLoop::Render() {
			
		}
		
		void GameLoop::Input() {

		}

		
		void GameLoop::ScoreSet(int Score) {
			score = Score;
		}
		int GameLoop::ScoreGet() const{
			return score;
		}


}