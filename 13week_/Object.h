#pragma once


namespace GameEngine {
	class Component {

	public:	Component() {


	}
	public:	~Component() {

	}

	};

	class Object {

		int x;
		int y;

	public: Object() {

	}
	public:~Object() {

	}
	
		  std::vector<Component*> Compoentlist;

	};

	
	
}