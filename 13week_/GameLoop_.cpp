#include "GameLoop_.h"

using namespace GameEngine;
GameLoop_::GameLoop_() : targetFPS(30), frameDelay(1000 / targetFPS) {
	score = 0;
	Gamestate = Title;
	start = false;
	viewScene = NULL;

}
GameLoop_::~GameLoop_() {

}

void GameLoop_::startLoop_() {	
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

void GameLoop_::init() {

	SceneCreate(Gamestate);

}

void GameLoop_::SceneCreate(state state) {

	switch (state) {
	case Title: viewScene = new GameEngine::Title(); break;
	case Game: viewScene = new GameEngine::Game(); break;
	case Rank: viewScene = new GameEngine::Rank(); break;
	case Exit: viewScene = NULL; break;



	}

}

void GameLoop_::Update() {


}

void GameLoop_::Render() {

}

void GameLoop_::Input() {

}


void GameLoop_::ScoreSet(int Score) {
	score = Score;
}
int GameLoop_::ScoreGet() const {
	return score;
}