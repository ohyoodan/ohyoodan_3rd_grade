#pragma once
#include <iostream>
#include <string>
#include <vector>



namespace GameEngine {


	class Component {

	public:	Component() {


	}
	public:	~Component() {

	}

	};

	class Object {
		
	private:
		std::string name;
		bool active;
		int x;
		int y;
		int z;
		std::vector<GameEngine::Component*> Compoentlist;

					
	public: Object(const int &X, const int &Y, const int &Z, const bool &Active , const std::string &Name);				

	~Object();
	
		  int GetX() const;
		  int GetY() const;
		  int GetZ() const;
		  bool GetActive() const;
		  std::string Getname() const;
		  
		  void SetX(int X);
		  void SetY(int Y);
		  void SetZ(int Z);
		  void SetActive(bool Active);
		  
		  void ComponentAdd(Component* Componet_);

		  
	};

	
	
}