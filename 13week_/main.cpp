/*
*제작자 : 오유단
제작일자: 2023년 6월 4일~
*/

#include "GameLoop_.h"
using namespace GameEngine;

int main() {
		
	system("cls"); //화면 초기화
	system("title  게임");//col = 100; row= 20 ;
	
	GameLoop_ GL;
	GL.startLoop_();



	return 0;

}