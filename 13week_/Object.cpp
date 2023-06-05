#include "Object.h"

namespace GameEngine {

	Object::Object(const int& X, const int& Y, const int& Z, const bool& Active, const std::string& Name){
	x = X;
	y = Y;
	z = Z;
	active = Active;
	name = Name;
	}

	int Object::GetX() const { return x; }
	int Object::GetY() const { return y; }
	int Object::GetZ() const { return z; }
	bool Object::GetActive() const { return active; }
	std::string Object::Getname() const { return name; }

	void Object::SetX(int X) { x = X; }
	void Object::SetY(int Y) { x = Y; }
	void Object::SetZ(int Z) { x = Z; }
	void Object::SetActive(bool Active) { active = Active; }
	
	Object::~Object() {};

	void Object::ComponentAdd(Component* Componet_) {
		Compoentlist.push_back(Componet_);
	}
}