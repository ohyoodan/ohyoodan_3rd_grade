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

		CHAR_INFO buffer1[BUFFER_DEPTH][BUFFER_HEIGHT][BUFFER_WIDTH];
		
		Button_state button_state;

		WORD Color(int text, int background);

	public: Scene();


	~Scene();

		virtual void DrawOut();


		  void ObjectAdd(int& X, int& Y, int& Z, Object* Obj);
		  void ObjectRemove(Object* Obj);

		  void clear();

		  CHAR_INFO(&GetBuffer())[BUFFER_DEPTH][BUFFER_HEIGHT][BUFFER_WIDTH];		  		  
		  		  
		   Button_state ButtonGet();

		   virtual void ButtonInput(int i);

		   virtual state OutScene();
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

	state OutScene()override;
		
	void Up();
		
	void Down();

	void DrawOut() override;
	
	void Game_R();

	void Rank_R();

	void Exit_R();
	
	void Title_R();
	void ButtonInput(int i) override;
	};

	class Game_: public Scene {

	public: Game_();

	~Game_();

	void ButtonInput(int i)override;

	void DrawOut()override;

	state OutScene()override;
	
	};

	class Rank_: public Scene {

	public: Rank_();

	 ~Rank_();

	};



}
