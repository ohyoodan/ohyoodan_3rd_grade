#include "Buffers.h"


namespace GameEngine{

	Buffers::Buffers() {
		buffer1;
		buffer2;
		currentBuffer = buffer1;//ȭ�� ����
		nextBuffer = buffer2;//ȭ�� ����
	}

	void Buffers::SetcurrentBuffer(CHAR_INFO cell,int z,int y ,int x) {//

		currentBuffer[z][y][x] = cell;

	}
	
	void Buffers::SetBuffer(CHAR_INFO(&cell)[BUFFER_HEIGHT][BUFFER_WIDTH]){
		//std::copy(&cell[0][0], &cell[0][0]+ BUFFER_HEIGHT*BUFFER_WIDTH,&currentBuffer);
	}

	
}