
#include "GameLoop_.h"
#include "GameEnum.h"

using namespace GameEngine;
GameLoop_::GameLoop_() : targetFPS(30), frameDelay(1000 / targetFPS) {
	score = 0;
	Gamestate = Title;
	start_Loop = true;
	
	//커서 설정 핸들
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);	

	//RenderHandle
	renderHandle = GameEngine::RenderHandle();
}
GameLoop_::~GameLoop_() {

}

void GameLoop_::startLoop_() {	
	init();
	while (start_Loop) {
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
	GameEnd();
}

void GameLoop_::init() {
	//std::thread inputThread(InputThread);
	SetConsoleWindowSize();
	//SceneCreate(Gamestate);		
	Cursor_Active(false);
	//renderHandle.ChangeScene(Gamestate);
}

void GameLoop_::SceneCreate(state state) {

	switch (state) {
	case Title:  break;
	case Game:  break;
	case Rank:  break;
	case Exit:  break;
	}

}

void GameLoop_::Update() {
	renderHandle.Set_ObjectUpdate();
}

void GameLoop_::Render() {
	renderHandle.Drawing(hOut);
	renderHandle.ScreenFlipping();
	
}

void GameLoop_::Input() {

}


void GameLoop_::ScoreSet(int Score) {
	score = Score;
}
int GameLoop_::ScoreGet() const {
	return score;
}

void GameLoop_::GameEnd() {

	
}

void GameLoop_::Cursor_Active(bool visible) {
	cInfo.dwSize = 10;//커서 크기 10~100
	cInfo.bVisible = visible;//커서 출력여부
	SetConsoleCursorInfo(hOut, &cInfo);
}


void GameLoop_:: SetConsoleWindowSize() {	
	SMALL_RECT windowRect;
	windowRect.Left = 0;
	windowRect.Top = 0;
	windowRect.Right = BUFFER_WIDTH - 1;
	windowRect.Bottom = BUFFER_HEIGHT - 1;

	COORD bufferSize;
	bufferSize.X = BUFFER_WIDTH;
	bufferSize.Y = BUFFER_HEIGHT;

	SetConsoleWindowInfo(hOut, TRUE, &windowRect);
	SetConsoleScreenBufferSize(hOut, bufferSize);
}

state GameLoop_::GamestateGet() const {

	return Gamestate;

}