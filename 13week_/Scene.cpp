#include "Scene.h"


namespace GameEngine {

	
	std::string Scene::Draw() {		
		return "test";
	}

	void Scene::clear() {

		

	}
	Scene::Scene(){
	
	};
	Scene::~Scene() {};
	void Scene::ObjectAdd(int &X, int &Y, int &Z, Object* Obj) {

		ObjectList.push_back(Obj);

	}
  
	//=============================================================================================


	Title::Title():Menu(Game) {
		
	}
	Title::~Title() {


	}

	void Title::Up() {
		switch (Menu)
		{
		case Game: Menu == Game; break;
		case Rank: Menu == Game; break;
		case Exit: Menu == Rank; break;
		}
	}

	void Title::Down() {
		switch (Menu)
		{
		case Game: Menu == Rank; break;
		case Rank: Menu == Exit; break;
		case Exit: Menu == Exit; break;
			
		}
	}

	void Title::Enter() {
		switch (Menu)
		{
		case Game: break;
		case Rank: break;
		case Exit: break;
		}
	}

	std::string Title::Draw(){
		std::string str;
		switch (Menu)
		{
		case Game: str = Game_R(); return str;  break;
		case Rank:Rank_R();  break;
		case Exit:Exit_R();  break;
		}
	}
	std::string Title::Game_R() {
		return "Game\nRank\nExit\n";
	}

	void Title::Rank_R() {

	}

	void Title::Exit_R() {


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