#pragma once
#include <string>
#include <vector>
#include <Windows.h>
#include <iostream>
#include "Object_.h"


namespace GameEngine {
	
	class Object;

	class Scene {
		int col;
		int row;
		int z_z;
		std::vector<GameEngine::Object*> ObjectList;
		
		

		


	public: Scene();


	public: ~Scene();

		  virtual std::string Draw();


		  void ObjectAdd(int& X, int& Y, int& Z, Object* Obj);


		  void clear();

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



	std::string Draw() override;
		 
	private:
	std::string Game_R();

	void Rank_R();

	void Exit_R();
	

	};

	class Game_: public Scene {

	public: Game_();

	~Game_();


	};

	class Rank_ : public Scene {

	public: Rank_();

	 ~Rank_();

	};



}
