#pragma once
#include "Scene.h"
#include "GameEnum.h"
#include <algorithm>
namespace GameEngine {
	
	class RenderHandle
	{


	private:

		Scene* scene;
		COORD topLeft;
		CHAR_INFO(*SceneBuffer)[BUFFER_HEIGHT][BUFFER_WIDTH];
		CHAR_INFO currentBuffer[BUFFER_HEIGHT][BUFFER_WIDTH];
		CHAR_INFO nextBuffer[BUFFER_HEIGHT][BUFFER_WIDTH];
		SMALL_RECT consoleWriteArea;
		COORD bufferSize;
	public:
		RenderHandle();
		~RenderHandle();

		void ChangeScene(state state);

		void ScreenClear();

		void ScreenFlipping();

		void ScreenRelease();

		void Set_ObjectUpdate();

		void Drawing(HANDLE handle);		

		void Printing(HANDLE handle);

		Button_state ButtonGet();
		
		void Button_input(int i);

		//state SceneChangeEvent();
	};
}

