#include "RenderHandle.h"




namespace GameEngine {
	//버퍼 순서 : 업데이트 >> 렌더링>> 스와이프 
	//dynamic_cast
	//https://blockdmask.tistory.com/241?category=249597
	RenderHandle::RenderHandle() {
		//scene = new Scene();	
		scene = new Title_();
		CHAR_INFO(*currentBuffer)[BUFFER_HEIGHT][BUFFER_WIDTH] = scene->GetBuffer();
		CHAR_INFO(*nextBuffer)[BUFFER_HEIGHT][BUFFER_WIDTH]= scene->GetBuffer();
	}
	RenderHandle::~RenderHandle() {
		ScreenRelease();		
	}
	
	void RenderHandle::ChangeScene(state state) {					
			ScreenRelease();	
			scene = new Title_();
	}
	void RenderHandle::Title() {
		scene = new Title_();
	}
	void RenderHandle::ScreenClear() {
		scene->clear();
	}

	
	void RenderHandle::ScreenFlipping() {//스와이프3순
		std::swap(currentBuffer, nextBuffer);
	}

	void RenderHandle::ScreenRelease() {
	//삭제
		delete scene;
	}
	void RenderHandle::Set_ObjectUpdate() {//Update1순
		Title();
		scene->DrawOut();		
		currentBuffer = scene->GetBuffer();
	}
	void RenderHandle::Drawing(HANDLE handle) {
		//Render2순

		COORD topLeft = { 0, 0 };//콘솔 내 좌표
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;//구조체
		GetConsoleScreenBufferInfo(handle, &consoleInfo);//현재 화면 정보 얻기
		COORD bufferSize = { BUFFER_WIDTH, BUFFER_HEIGHT };// 콘솔 내 좌표
		SMALL_RECT consoleWriteArea = { 0, 0, BUFFER_WIDTH - 1, BUFFER_HEIGHT - 1 };// 콘솔창 크기와 위치

		CHAR_INFO consoleBuffer[BUFFER_HEIGHT][BUFFER_WIDTH];
		for (int y = 0; y < BUFFER_HEIGHT; ++y) {
			for (int x = 0; x < BUFFER_WIDTH; ++x) {
				for (int z = BUFFER_DEPTH - 1; z >= 0; --z) {//z값이 높을 수록 뒤

					consoleBuffer[y][x] = currentBuffer[z][y][x];					
				}
			}
		}

		WriteConsoleOutput(handle, (CHAR_INFO*)consoleBuffer, bufferSize, topLeft, &consoleWriteArea);
		//핸들, 구조체배열,구조체크기,출력위치,출력할 영역
	}	
}