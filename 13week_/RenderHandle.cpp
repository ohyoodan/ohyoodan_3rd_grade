#include "RenderHandle.h"




namespace GameEngine {
			
	RenderHandle::RenderHandle() {		
			topLeft = { 0, 0 };//�ܼ� �� ��ǥ
			consoleWriteArea = { 0, 0, BUFFER_WIDTH - 1, BUFFER_HEIGHT - 1 };//�ܼ�â ��ġ�� ũ��
			bufferSize = { BUFFER_WIDTH, BUFFER_HEIGHT };// �ܼ� �� ��ǥ
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

	
	void RenderHandle::ScreenFlipping() {//��������3��
		std::swap(currentBuffer, nextBuffer);
	}

	void RenderHandle::ScreenRelease() {
		if (scene == nullptr) {

		}else {
			delete scene;
		}
		
	}
	void RenderHandle::Set_ObjectUpdate() {//Update1��				
		scene->DrawOut();		
		SceneBuffer = scene->GetBuffer();
	}
	void RenderHandle::Drawing(HANDLE handle) {
		//Render2��		
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;//����ü
		GetConsoleScreenBufferInfo(handle, &consoleInfo);//���� ȭ�� ���� ���		
		
		
		for (int y = 0; y < BUFFER_HEIGHT; ++y) {
			for (int x = 0; x < BUFFER_WIDTH; ++x) {
				for (int z = BUFFER_DEPTH - 1; z >= 0; --z) {//z���� ���� ���� ��

					nextBuffer[y][x] = SceneBuffer[z][y][x];
				}
			}
		}
		
	}	

	void RenderHandle::Printing(HANDLE handle) {
		//Render2��
		WriteConsoleOutput(handle, (CHAR_INFO*)nextBuffer, bufferSize, topLeft, &consoleWriteArea);
		//�ڵ�, ����ü�迭,����üũ��,�����ġ,����� ����
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