#include<iostream>
#include <vector>
#include <windows.h>
#include <chrono>// �ð� 
#include <thread>;
#include "Game_Loop.h"
#include "Scene.h"
#include "Object.h"


void main() {
	system("mode con:cols=100 lines=20 | title ����");
	GameEngine::GameLoop GL;
	GL.start_L();
	
}