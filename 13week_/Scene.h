#pragma once
#include <string>
#include <vector>
#include <Windows.h>
#include <iostream>
#include "Object_.h"
#include "GameEnum.h"

namespace GameEngine {
	
	class Object;

	class Scene {
	protected:
		std::vector<GameEngine::Object*> ObjectList;	
		CHAR_INFO scene_Object[BUFFER_DEPTH][BUFFER_HEIGHT][BUFFER_WIDTH];//화면 셋팅
		
		bool ArrowKey;		

		CHAR_INFO buffer1[BUFFER_DEPTH][BUFFER_HEIGHT][BUFFER_WIDTH];
		
		

	public: Scene();


	~Scene();

		  virtual CHAR_INFO(*DrawOut())[BUFFER_DEPTH][BUFFER_HEIGHT][BUFFER_WIDTH];


		  void ObjectAdd(int& X, int& Y, int& Z, Object* Obj);


		  void clear();

		  CHAR_INFO(&GetBuffer())[BUFFER_DEPTH][BUFFER_HEIGHT][BUFFER_WIDTH];
		  
		  WORD Color(int text,int background);
		  
		  

	};

	class Title_:public Scene{

		enum Menu {
			Game,
			Rank,
			Exit,
		};

		Menu Menu;
	public: Title_();

	
	~Title_();

	void Enter();
		
	

	void Up();
		
	
	
	void Down();



	CHAR_INFO(*DrawOut())[BUFFER_DEPTH][BUFFER_HEIGHT][BUFFER_WIDTH] override;
	
	
	void Game_R();

	void Rank_R();

	void Exit_R();
	

	};

	class Game_: public Scene {

	public: Game_();

	~Game_();


	};

	class Rank_: public Scene {

	public: Rank_();

	 ~Rank_();

	};



}
