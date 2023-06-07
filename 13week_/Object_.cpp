#include "Object_.h"
using namespace GameEngine;
namespace GameEngine {

	Object_::Object_(const int& X, const int& Y, const int& Z, const bool& Active, const int& Size, const std::string& Name) {
		x = X;
		y = Y;
		z = Z;
		active = Active;
		size = Size;
		name = Name;
	}
	Object_::Object_() {};
		
	

	int Object_::GetX() const { return x; }
	int Object_::GetY() const { return y; }
	int Object_::GetZ() const { return z; }
	int Object_::GetSize() const { return size; }
	bool Object_::GetActive() const { return active; }
	std::string Object_::Getname() const { return name; }

	void Object_::SetX(int X) { x = X; }
	void Object_::SetY(int Y) { x = Y; }
	void Object_::SetZ(int Z) { x = Z; }
	void Object_::SetSize(int Size) { size = Size; }
	void Object_::SetActive(bool Active) { active = Active; }
	void Object_::SetName(std::string Name) { name = Name; }
	Object_::~Object_() {};

	void Object_::ComponentAdd(Component* Componet_) {
		Compoentlist.push_back(Componet_);
	}

	

	//=================================================================================================

	Player::Player():maxspeed(6)
	{
		SetX(-25);
		SetY(-15);
		SetZ(0);
		SetSize(4);
		SetName("Player");
		SetSpeed(3);
		jumping = false;
		gravity = false;
	}
	Player::~Player() {

	}

	void Player::SetSpeed(int Speed) {

	}

	int Player::GetSpeed() const{
		return speed;
	}

	void Player::Jump() {
		int X = GetX();
		int Y = GetY();
		if (X == -25 && Y == -15) {
			jumping = true;
		}		
		if (jumping == true) {
			SetX(GetX() + 1);
			SetY(GetY() + 1);
		}
		else if (gravity == true) {
			SetX(GetX() - 1);
			SetY(GetY() - 1);
		}		
		
		if ((10< X && 10<Y)&&gravity==false) {
			Jump();
		}
		else if ((X == -25 && Y == 15) && gravity == true) {
			gravity = false;
		}
		else {
			gravity = true;			
			Jump();
		}
		
	}
	
	//=================================================================================================

	void Rander::SetConsoleColor(int Text, int Background) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int color = text + (Background * 16);
		SetConsoleTextAttribute(hConsole, color);
	}

	void Rander::ReSetConsoleColor() {
		SetConsoleColor(7, 0);
	}

	void Rander::Draw() {


	}

	Rander::~Rander() {


	}

	//=================================================================================================

	

	Collider::Collider(Object_ &i) {
		size=i.GetSize();
	};

	Collider::~Collider() {};

	//=================================================================================================

	Component::Component() { };
	Component::~Component() { };

	
	//=================================================================================================




}
