#pragma once
#include "GameEnum.h"
#include <algorithm>
#include <Windows.h>
namespace GameEngine {
		
	class Buffers
	{
	
		CHAR_INFO buffer1[BUFFER_DEPTH][BUFFER_HEIGHT][BUFFER_WIDTH];
		CHAR_INFO buffer2[BUFFER_DEPTH][BUFFER_HEIGHT][BUFFER_WIDTH];

		CHAR_INFO(*currentBuffer)[BUFFER_HEIGHT][BUFFER_WIDTH];
		CHAR_INFO(*nextBuffer)[BUFFER_HEIGHT][BUFFER_WIDTH];

	public:
		Buffers();
		
		void SetcurrentBuffer(CHAR_INFO cell, int z, int y, int x);

		void SetBuffer(CHAR_INFO(&cell)[BUFFER_HEIGHT][BUFFER_WIDTH]);

		void SwapBuffers();
			
		
	};

}