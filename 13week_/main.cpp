#include "Game_Loop.h"


/*
2023�� 06�� 03�� ������ 
*/

int main() {
	
	system("mode con:cols=100 lines=20 | title ����");//col = 100; row= 20 ;
	GameEngine::GameLoop GL;
	GL.start_L();
	
	
	
	return 0;
}