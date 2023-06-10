#pragma once
#include "Scene.h"
#include "GameEnum.h"
#include <algorithm>
namespace GameEngine {
	
	class RenderHandle
	{


	private:

		Scene* scene;
		
		CHAR_INFO(*currentBuffer)[BUFFER_HEIGHT][BUFFER_WIDTH];
		CHAR_INFO(*nextBuffer)[BUFFER_HEIGHT][BUFFER_WIDTH];
		
	public:
		RenderHandle();
		~RenderHandle();

		void ChangeScene(state state);




		void ScreenClear();

		void ScreenFlipping();

		void ScreenRelease();


		void Set_ObjectUpdate();		
					
		void Drawing(HANDLE handle);

		
		void Title();
		

	};
}

