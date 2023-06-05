#include "Game_Loop.h"


/*
2023년 06월 03일 오유단 
*/

int main() {
	
	system("mode con:cols=100 lines=20 | title 고구마");//col = 100; row= 20 ;
	GameEngine::GameLoop GL;
	GL.start_L();
	
	
	
	return 0;
}