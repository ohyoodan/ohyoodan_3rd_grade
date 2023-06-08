#pragma once
#include<iostream>
#include <vector>//�ڷ���
#include <windows.h>
#include <chrono>// �ð� 
#include <thread>// ������
#include <fstream>//����
#include <string>// ���ڿ�
#include "Scene.h"
#include "Object_.h"
#include "Command.h"
namespace GameEngine {
	class GameLoop_
	{

		int g_nScreenIndex;
		const int targetFPS;
		const int frameDelay;
		bool start_Loop;
		int score;
		
		


		HANDLE hOut;
		CONSOLE_CURSOR_INFO cInfo;

		HANDLE g_hScreen[2];

		GameEngine::Scene* viewScene;

		state Gamestate;

	public:
		GameLoop_();
		~GameLoop_();

		void startLoop_();
		int ScoreGet() const;


	private:
		void init();
		void SceneCreate(state state);
		void Update();
		void Render();
		void Input();
		void ScoreSet(int Score);


		void GameEnd();

		void ScreenClear();

		void ScreenFlipping();

		void Cursor_Active(bool visible);

		void ScreenRelease();

		void ScreenPrint(int x, int y, std::string& string);
		

	};


}

	


