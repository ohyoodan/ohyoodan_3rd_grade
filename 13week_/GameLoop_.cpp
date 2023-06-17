
#include "GameLoop_.h"
#include "GameEnum.h"

using namespace GameEngine;
GameLoop_::GameLoop_() : targetFPS(30), frameDelay(1000 / targetFPS), button_ev(0) {
	score = 0;
	Gamestate = Title;
	start_Loop = true;	
	
	//커서 설정 핸들
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);	

	//RenderHandle
	renderHandle = new GameEngine::RenderHandle();		

	eventHandle = new GameEngine::Event_Handler();
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
	
	SetConsoleWindowSize();
	
	Cursor_Active(false);
	
	SceneChange(Gamestate);				
			
	InputButtonSet();
		
}

void GameLoop_::InputButtonSet() {
	if (inputHandle == nullptr) {
		inputHandle = new GameEngine::InputHandle(renderHandle->ButtonGet());
	}
	else {	
		inputHandle->button_set(renderHandle->ButtonGet());
	}
}

void GameLoop_::SceneChange(state state) {

	switch (state) {
	case Title: renderHandle->ChangeScene(Gamestate); break;
	case Game:  renderHandle->ChangeScene(Gamestate); break;
	case Rank:  renderHandle->ChangeScene(Gamestate); break;
	case Exit:   break;
	}

}

void GameLoop_::Update() {
	
	renderHandle->Set_ObjectUpdate();
	renderHandle->Drawing(hOut);
	
}

void GameLoop_::Render() {	
	renderHandle->Printing(hOut);
	renderHandle->ScreenFlipping();	
}

void GameLoop_::Input() {

	button_ev=inputHandle->KeyCheck();
	renderHandle->Button_input(button_ev);
	button_ev = 0;
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