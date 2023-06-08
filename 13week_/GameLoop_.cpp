#include "GameLoop_.h"
#include "SceneHandle.h"
#include "GameEnum.h"

using namespace GameEngine;
GameLoop_::GameLoop_() : targetFPS(30), frameDelay(1000 / targetFPS) {
	score = 0;
	Gamestate = Title;
	start_Loop = true;
	viewScene = NULL;

	//커서 설정 핸들
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);	

	//이중 화면 버퍼
	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	
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
	SceneHandle* i;
	SceneCreate(Gamestate);		
	Cursor_Active(false);
}

void GameLoop_::SceneCreate(state state) {

	switch (state) {
	case Title: viewScene = new GameEngine::Title_; break;
	case Game: viewScene = new GameEngine::Game_; break;
	case Rank: viewScene = new GameEngine::Rank_; break;
	case Exit: viewScene = NULL; break;
	}

}

void GameLoop_::Update() {


}

void GameLoop_::Render() {
	ScreenClear();
	std::string str = viewScene->Draw();
	ScreenPrint(48, 10,str );
	ScreenFlipping();
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

	ScreenRelease();

}

void GameLoop_::ScreenClear()
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 101 * 20, Coor, &dw);
}

void GameLoop_::ScreenFlipping() {
	
		SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
		g_nScreenIndex = !g_nScreenIndex;
	
}

void GameLoop_::Cursor_Active(bool visible) {
	cInfo.dwSize = 10;//커서 크기 10~100
	cInfo.bVisible = visible;//커서 출력여부
	SetConsoleCursorInfo(hOut, &cInfo);
}



void GameLoop_::ScreenRelease()
{
	CloseHandle(g_hScreen[0]);
	CloseHandle(g_hScreen[1]);
}

void GameLoop_::ScreenPrint(int x,int y, std::string& string) {
	DWORD dw;
	COORD CursorPosition = { x, y };
	WriteFile(g_hScreen[g_nScreenIndex], string.c_str(), string.length(), &dw, NULL);
	CursorPosition.X = x + 1;
	CursorPosition.Y =y+1;
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);	
	int color = 1 + (15 * 16);
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);

	
	WriteFile(g_hScreen[g_nScreenIndex], string.c_str(), string.length(), &dw, NULL);
}