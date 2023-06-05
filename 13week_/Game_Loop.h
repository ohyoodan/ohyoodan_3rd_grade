#pragma once
#include<iostream>
#include <vector>//�ڷ���
#include <windows.h>
#include <chrono>// �ð� 
#include <thread>// ������
#include <fstream>//����
#include <string>// ���ڿ�
#include "Scene.h"
#include "Object.h"


namespace GameEngine {

	class GameLoop {

		const int targetFPS; 
		const int frameDelay;
		bool start;
		int score;

		enum state {
			Title,
		};
		GameEngine::Scene* viewScene;

		state Gamestate;

	public: GameLoop();


	 ~GameLoop();


	 void start_L();
	 int ScoreGet() const;


	private: 
		void init();
		void SceneCreate(state state);
		void Update();
		void Render();
		void Input();
		void ScoreSet(int Score);
	
		

	};
	
	




}