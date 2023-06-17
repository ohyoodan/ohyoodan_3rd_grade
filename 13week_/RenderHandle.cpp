#include "RenderHandle.h"




namespace GameEngine {
			
	RenderHandle::RenderHandle() {		
			topLeft = { 0, 0 };//콘솔 내 좌표
			consoleWriteArea = { 0, 0, BUFFER_WIDTH - 1, BUFFER_HEIGHT - 1 };//콘솔창 위치와 크기
			bufferSize = { BUFFER_WIDTH, BUFFER_HEIGHT };// 콘솔 내 좌표
			CHAR_INFO(*SceneBuffer)[BUFFER_HEIGHT][BUFFER_WIDTH];
			
			CHAR_INFO currentBuffer[BUFFER_HEIGHT][BUFFER_WIDTH];
			CHAR_INFO nextBuffer[BUFFER_HEIGHT][BUFFER_WIDTH];
	}
	RenderHandle::~RenderHandle() {
		ScreenRelease();		
	}
	


	void RenderHandle::ChangeScene(state state) {					
		ScreenRelease();
			switch (state)
			{
			case Title: scene=new Title_();
				break;
			case Game:
				break;
			case Rank:
				break;
			case Exit:
				break;
			default:
				break;
			}
	}	
	void RenderHandle::ScreenClear() {
		scene->clear();
	}

	
	void RenderHandle::ScreenFlipping() {//스와이프3순
		std::swap(currentBuffer, nextBuffer);
	}

	void RenderHandle::ScreenRelease() {
		if (scene == nullptr) {

		}else {
			delete scene;
		}
		
	}
	void RenderHandle::Set_ObjectUpdate() {//Update1순				
		scene->DrawOut();		
		SceneBuffer = scene->GetBuffer();
	}
	void RenderHandle::Drawing(HANDLE handle) {
		//Render2순		
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;//구조체
		GetConsoleScreenBufferInfo(handle, &consoleInfo);//현재 화면 정보 얻기		
		
		
		for (int y = 0; y < BUFFER_HEIGHT; ++y) {
			for (int x = 0; x < BUFFER_WIDTH; ++x) {
				for (int z = BUFFER_DEPTH - 1; z >= 0; --z) {//z값이 높을 수록 뒤

					nextBuffer[y][x] = SceneBuffer[z][y][x];
				}
			}
		}
		
	}	

	void RenderHandle::Printing(HANDLE handle) {
		//Render2순
		WriteConsoleOutput(handle, (CHAR_INFO*)nextBuffer, bufferSize, topLeft, &consoleWriteArea);
		//핸들, 구조체배열,구조체크기,출력위치,출력할 영역
	}

	Button_state RenderHandle::ButtonGet() {		
		return scene->ButtonGet();
	}

	void RenderHandle::Button_input(int i) {
		if (i == NULL) {

		}
		else {
			scene->ButtonInput(i);
		}
		
	}

	/*state RenderHandle::SceneChangeEvent() {

		
	}*/

}