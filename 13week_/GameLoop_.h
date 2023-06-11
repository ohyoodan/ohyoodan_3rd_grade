#pragma once
#include<iostream>
#include <vector>//자료형
#include <windows.h>
#include <chrono>// 시간 
#include <thread>// 스레드
#include <fstream>//파일
#include <string>// 문자열
#include "Scene.h"
#include "Object_.h"
#include "Command.h"
#include "GameEnum.h"
#include "RenderHandle.h"
#include "InputHandle.h"
#include <mutex>


namespace GameEngine {
	
	class GameLoop_
	{
	private:
		
		const int targetFPS;
		const int frameDelay;
		bool start_Loop;
		int score;
		
		std::mutex mtx;
		int button_ev;

		HANDLE hOut;
		CONSOLE_CURSOR_INFO cInfo;		
		state Gamestate;
		std::thread inputThread;

		GameEngine::RenderHandle* renderHandle;
		GameEngine::InputHandle* inputHandle;

		bool SceneChangeEvent;

		bool SceneChangeEventChack();

	public:		
		GameLoop_();
		~GameLoop_();

		void startLoop_();
		int ScoreGet() const;
		state GamestateGet() const;

	private:
		void init();
		void SceneChange(state state);
		void Update();
		void Render();
		void Input();
		void ScoreSet(int Score);
		

		void GameEnd();
		
		void Cursor_Active(bool visible);
		
		void SetConsoleWindowSize();

	};


}

	


