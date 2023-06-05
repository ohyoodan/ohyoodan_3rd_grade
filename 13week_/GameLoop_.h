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


		const int targetFPS;
		const int frameDelay;
		bool start;
		int score;

		enum state {
			Title,
			Game,
			Rank,
			Exit,
		};
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








	};




}

	


