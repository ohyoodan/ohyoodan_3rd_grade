#pragma once
#include <string>
#include <vector>
#include <Windows.h>
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

		  void Draw();


		  void ObjectAdd(int& X, int& Y, int& Z, Object* Obj);


		  void clear();

	};

	class Title:public Scene{

	public: Title();

	
	~Title();

	

	};

	class Game : public Scene {

	public: Game();

	~Game();


	};

	class Rank : public Scene {

	public: Rank();

	 ~Rank();

	};



}
