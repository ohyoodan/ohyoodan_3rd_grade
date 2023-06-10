#include "RenderHandle.h"




namespace GameEngine {
	//���� ���� : ������Ʈ >> ������>> �������� 
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

	
	void RenderHandle::ScreenFlipping() {//��������3��
		std::swap(currentBuffer, nextBuffer);
	}

	void RenderHandle::ScreenRelease() {
	//����
		delete scene;
	}
	void RenderHandle::Set_ObjectUpdate() {//Update1��
		Title();
		scene->DrawOut();		
		currentBuffer = scene->GetBuffer();
	}
	void RenderHandle::Drawing(HANDLE handle) {
		//Render2��

		COORD topLeft = { 0, 0 };//�ܼ� �� ��ǥ
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;//����ü
		GetConsoleScreenBufferInfo(handle, &consoleInfo);//���� ȭ�� ���� ���
		COORD bufferSize = { BUFFER_WIDTH, BUFFER_HEIGHT };// �ܼ� �� ��ǥ
		SMALL_RECT consoleWriteArea = { 0, 0, BUFFER_WIDTH - 1, BUFFER_HEIGHT - 1 };// �ܼ�â ũ��� ��ġ

		CHAR_INFO consoleBuffer[BUFFER_HEIGHT][BUFFER_WIDTH];
		for (int y = 0; y < BUFFER_HEIGHT; ++y) {
			for (int x = 0; x < BUFFER_WIDTH; ++x) {
				for (int z = BUFFER_DEPTH - 1; z >= 0; --z) {//z���� ���� ���� ��

					consoleBuffer[y][x] = currentBuffer[z][y][x];					
				}
			}
		}

		WriteConsoleOutput(handle, (CHAR_INFO*)consoleBuffer, bufferSize, topLeft, &consoleWriteArea);
		//�ڵ�, ����ü�迭,����üũ��,�����ġ,����� ����
	}	
}