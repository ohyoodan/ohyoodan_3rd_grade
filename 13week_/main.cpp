#include "GameLoop_.h"
using namespace GameEngine;

int main() {
		
	//system("cls"); //화면 초기화
	system("mode con:cols=101 lines=20 | title 직사각형 게임");//col = 100; row= 20 ;
	
	GameLoop_ GL;
	GL.startLoop_();



	return 0;

}