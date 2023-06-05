#include "Scene.h"


namespace GameEngine {


	void Scene::Draw() {
		
	}

	void Scene::clear() {

		

	}
	Scene::Scene() {
	
	};
	Scene::~Scene() {};
	void Scene::ObjectAdd(int &X, int &Y, int &Z, Object* Obj) {

		ObjectList.push_back(Obj);

	}
  
	//=============================================================================================


	Title::Title() {

	}
	Title::~Title() {


	}

	//=============================================================================================


	Game::Game() {



	}
	Game::~Game() {



	}

	//===============================================================================================

	Rank::Rank() {

	}
	Rank::~Rank() {

	}
}