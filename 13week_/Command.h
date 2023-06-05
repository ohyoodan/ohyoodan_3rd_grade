#pragma once
#include "Object.h"
namespace GameEngine{

	class Command {
	public :
		virtual ~Command();
		virtual void exetude(Object& objcet);

	};

	class InputHandler {

	public: void handleInput();

	};

	class JumpCmaand : public Command {
	public:
		virtual void execute(Object& object);
	};

}