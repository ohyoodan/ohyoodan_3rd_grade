#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include "string"

namespace GameEngine {

	class Component {

	public:	Component();

		  ~Component();

	};

	class Object_
	{


	private:
		std::string name;
		bool active;
		int x;
		int y;
		int z;
		std::vector<Component*> Compoentlist;
		int size;

	public: Object_(const int& X, const int& Y, const int& Z, const bool& Active,const int &Size, const std::string& Name);
		  Object_();
		  ~Object_();
		  int GetX() const;
		  int GetY() const;
		  int GetZ() const;
		  int GetSize()const;
		  bool GetActive() const;
		  std::string Getname() const;

		  void SetX(int X);
		  void SetY(int Y);
		  void SetZ(int Z);
		  void SetSize(int Size);
		  void SetActive(bool Active);
		  void SetName(std::string Name);

		  void ComponentAdd(Component* Componet_);

		  

	};
	
	class Player :
		public Object_
	{
	public: 
		Player();
		
		  
		~Player();
		  

	};

	class Rander :public Component {
		
		void SetConsoleColor(int text, int background);

		void ReSetConsoleColor();

		void Draw();

	};

	class Collider :public Component {
		int size;

		Collider(Object_ &i);

		~Collider();



	};
}


