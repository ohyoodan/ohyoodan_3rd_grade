#include<iostream>
#include <vector>
#include <windows.h>
#include <chrono>// 시간 
#include <thread>;
#include "Game_Loop.h"
#include "Scene.h"
#include "Object.h"


void main() {
	system("mode con:cols=100 lines=20 | title 고구마");
	GameEngine::GameLoop GL;
	GL.start_L();
	
}