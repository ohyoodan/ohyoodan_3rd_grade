#pragma once
#include "Object_.h"
namespace GameEngine{

	class Command {
	public :
		virtual ~Command();
		virtual void exetude(Object_& objcet);

	};

	class InputHandler {

	public: void handleInput();

	};

	class JumpCmaand : public Command {
	public:
		virtual void execute(Object_& object);
	};

}