#include "Object_.h"
using namespace GameEngine;
Object_::Object_(const int& X, const int& Y, const int& Z, const bool& Active, const std::string& Name) {
	x = X;
	y = Y;
	z = Z;
	active = Active;
	name = Name;
}

int Object_::GetX() const { return x; }
int Object_::GetY() const { return y; }
int Object_::GetZ() const { return z; }
bool Object_::GetActive() const { return active; }
std::string Object_::Getname() const { return name; }

void Object_::SetX(int X) { x = X; }
void Object_::SetY(int Y) { x = Y; }
void Object_::SetZ(int Z) { x = Z; }
void Object_::SetActive(bool Active) { active = Active; }

Object_::~Object_() {};

void Object_::ComponentAdd(Component* Componet_) {
	Compoentlist.push_back(Componet_);
}