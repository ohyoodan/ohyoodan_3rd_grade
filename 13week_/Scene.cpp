#include "Scene.h"


namespace GameEngine {


	void Scene::DrawOut(){
		
	}

	void Scene::clear() {
		for (int z = 0; z < BUFFER_DEPTH; ++z) {
			for (int y = 0; y < BUFFER_HEIGHT; ++y) {
				for (int x = 0; x < BUFFER_WIDTH; ++x) {
					scene_Object[z][y][x] = { ' ',Color(0,0) };
				}
			}
		}
	}

	CHAR_INFO(&Scene::GetBuffer())[BUFFER_DEPTH][BUFFER_HEIGHT][BUFFER_WIDTH]{

		return scene_Object;

	}
	Scene::Scene() {
		for (auto* object : ObjectList) {
			delete object;
		}
	};

	Scene::~Scene() {};
	void Scene::ObjectAdd(int& X, int& Y, int& Z, Object* Obj) {

		ObjectList.push_back(Obj);

	}

	void Scene::ObjectRemove(Object* Obj) {
		// 요소를 검색하여 제거
		auto it = std::find(ObjectList.begin(), ObjectList.end(), Obj);
		if (it != ObjectList.end()) {
			ObjectList.erase(it);
		}
		// 메모리 해제
		delete Obj;
	}

	WORD Scene::Color(int text, int background) {
		int color = text + (background * 16);
		WORD attributes = 0;
		for (int i = 0; i < sizeof(WORD) * 8; ++i) {
			int bit = (color >> i) & 1;
			attributes |= (bit << i);
		}
		/*0: 검정색
		1 : 파란색
		2 : 초록색
		3 : 청록색
		4 : 빨간색
		5 : 자주색
		6 : 노란색
		7 : 흰색
		8 : 회색
		9 : 밝은 파란색
		10 : 밝은 초록색
		11 : 밝은 청록색
		12 : 밝은 빨간색
		13 : 밝은 자주색
		14 : 밝은 노란색
		15 : 밝은 흰색*/
		return attributes;
	}

	 Button_state Scene::ButtonGet() {
		return button_state;
	}

	 void Scene::ButtonInput(int i) {

	 }

	 state Scene::OutScene() {
		 return Title;
	 }
	//=============================================================================================


	Title_::Title_() :Menu(Game) {
		button_state = { true,true,true,true,true,false };//위,아래,엔터
	}
	Title_::~Title_() {


	}

	void Title_::Up() {
		switch (Menu)
		{
		case Game: Menu = Game; break;
		case Rank: Menu = Game; break;
		case Exit: Menu = Rank; break;
		}
	}

	void Title_::Down() {
		switch (Menu)
		{
		case Game: Menu = Rank; break;
		case Rank: Menu = Exit; break;
		case Exit: Menu = Exit; break;
		}

	}
	
	void Title_::DrawOut()
	{

		switch (Menu)
		{
		case Game:Game_R();  break;
		case Rank:Rank_R();  break;
		case Exit:Exit_R();  break;
		}
	
	}

	void Title_::Game_R(){
		clear();
				
		scene_Object[0][10][39] = { 'G', Color(7,4) };
		scene_Object[0][10][40] = { 'A', Color(7,4) };
		scene_Object[0][10][41] = { 'M', Color(7,4) };
		scene_Object[0][10][42] = { 'E', Color(7,4) };

		scene_Object[0][11][39] = { 'R',Color(0,7) };
		scene_Object[0][11][40] = { 'A',Color(0,7) };
		scene_Object[0][11][41] = { 'N',Color(0,7) };
		scene_Object[0][11][42] = { 'K',Color(0,7) };

		scene_Object[0][12][39] = { 'E',Color(0,7) };
		scene_Object[0][12][40] = { 'X',Color(0,7) };
		scene_Object[0][12][41] = { 'I',Color(0,7) };
		scene_Object[0][12][42] = { 'T',Color(0,7) };
	}

	void Title_::Rank_R() {
		clear();
		scene_Object[0][10][39] = { 'G', Color(0,7) };
		scene_Object[0][10][40] = { 'A', Color(0,7) };
		scene_Object[0][10][41] = { 'M', Color(0,7) };
		scene_Object[0][10][42] = { 'E', Color(0,7) };

		scene_Object[0][11][39] = { 'R',Color(7,4) };
		scene_Object[0][11][40] = { 'A',Color(7,4) };
		scene_Object[0][11][41] = { 'N',Color(7,4) };
		scene_Object[0][11][42] = { 'K',Color(7,4) };

		scene_Object[0][12][39] = { 'E',Color(0,7) };
		scene_Object[0][12][40] = { 'X',Color(0,7) };
		scene_Object[0][12][41] = { 'I',Color(0,7) };
		scene_Object[0][12][42] = { 'T',Color(0,7) };
	}

	void Title_::Exit_R() {
		clear();
		scene_Object[0][10][39] = { 'G', Color(0,7) };
		scene_Object[0][10][40] = { 'A', Color(0,7) };
		scene_Object[0][10][41] = { 'M', Color(0,7) };
		scene_Object[0][10][42] = { 'E', Color(0,7) };

		scene_Object[0][11][39] = { 'R',Color(0,7) };
		scene_Object[0][11][40] = { 'A',Color(0,7) };
		scene_Object[0][11][41] = { 'N',Color(0,7) };
		scene_Object[0][11][42] = { 'K',Color(0,7) };

		scene_Object[0][12][39] = { 'E',Color(7,4) };
		scene_Object[0][12][40] = { 'X',Color(7,4) };
		scene_Object[0][12][41] = { 'I',Color(7,4) };
		scene_Object[0][12][42] = { 'T',Color(7,4) };

	}
	void Title_::ButtonInput(int i) {
		switch (i)
		{
		case 1: Up(); break;
		case 2: Down(); break;
		case 3: Up(); break;
		case 4: Down(); break;
		case 5: OutScene(); break;
		default:
			break;
		}

	}

	state Title_::OutScene() {
		switch (Menu)
		{
		case GameEngine::Title_::Game: return state::Game;
			break;
		case GameEngine::Title_::Rank: return state::Rank;
			break;
		case GameEngine::Title_::Exit: return state::Exit;
			break;		
		}
		
	}

	//=============================================================================================


	Game_::Game_() {		
		button_state = { true,false,false,false,false,true };
	}
	Game_::~Game_() {

	}

	void Game_::ButtonInput(int i) {

	}

	void Game_::DrawOut() {

	}

	state Game_::OutScene() {
		return state::Title;
	}

	//===============================================================================================

	Rank_::Rank_() {

	}
	Rank_::~Rank_() {

	}
}