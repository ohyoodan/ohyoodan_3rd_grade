#include "Scene.h"


namespace GameEngine {


	CHAR_INFO(*Scene::DrawOut())[BUFFER_DEPTH][BUFFER_HEIGHT][BUFFER_WIDTH]{

		return &scene_Object;
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

	};
	Scene::~Scene() {};
	void Scene::ObjectAdd(int& X, int& Y, int& Z, Object* Obj) {

		ObjectList.push_back(Obj);

	}
	WORD Scene::Color(int text, int background) {
		int color = text + (background * 16);
		WORD attributes = 0;
		for (int i = 0; i < sizeof(WORD) * 8; ++i) {
			int bit = (color >> i) & 1;
			attributes |= (bit << i);
		}
		/*0: ������
		1 : �Ķ���
		2 : �ʷϻ�
		3 : û�ϻ�
		4 : ������
		5 : ���ֻ�
		6 : �����
		7 : ���
		8 : ȸ��
		9 : ���� �Ķ���
		10 : ���� �ʷϻ�
		11 : ���� û�ϻ�
		12 : ���� ������
		13 : ���� ���ֻ�
		14 : ���� �����
		15 : ���� ���*/
		return attributes;
	}

	//=============================================================================================


	Title_::Title_() :Menu(Game) {

	}
	Title_::~Title_() {


	}

	void Title_::Up() {
		switch (Menu)
		{
		case Game: Menu == Game; break;
		case Rank: Menu == Game; break;
		case Exit: Menu == Rank; break;
		}
	}

	void Title_::Down() {
		switch (Menu)
		{
		case Game: Menu == Rank; break;
		case Rank: Menu == Exit; break;
		case Exit: Menu == Exit; break;

		}

	}

	void Title_::Enter() { // ���⼭ Ÿ��Ʋ����ߵ�  ���� ���� �ش��̴�~�˷���ߵ�
		switch (Menu)
		{
		case Game: break;
		case Rank: break;
		case Exit: break;
		}
	}

	CHAR_INFO(*Title_::DrawOut())[BUFFER_DEPTH][BUFFER_HEIGHT][BUFFER_WIDTH]
	{

		switch (Menu)
		{
		case Game:Game_R();  break;
		case Rank:Rank_R();  break;
		case Exit:Exit_R();  break;
		}
	return &scene_Object;
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
	

	//=============================================================================================


	Game_::Game_() {



	}
	Game_::~Game_() {



	}

	//===============================================================================================

	Rank_::Rank_() {

	}
	Rank_::~Rank_() {

	}
}