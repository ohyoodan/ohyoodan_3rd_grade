#include "Command.h"

namespace GameEngine {

	Command::Command() {
		buttonPush = false;
	}
	Command::~Command() {

	}

	void Command::execute() {
		buttonPush = true;
	}

	void Command::execute(Object_& object) {

	}

	void Command::ButtonSet(bool t) {
		buttonPush = t;
	}

	//===================================================================================
	void UpCommand::execute() {
		buttonPush = true;
	}
	void UpCommand::execute(Object_& object) {

	}
	//===================================================================================
	void RightCommand::execute() {
		buttonPush = true;
	}
	void RightCommand::execute(Object_& object) {

	}
	//===================================================================================
	void DownCommand::execute() {
		buttonPush = true;
	}
	void DownCommand::execute(Object_& object) {

	}
	//===================================================================================
	void LeftCommand::execute() {
		buttonPush = true;
	}
	void LeftCommand::execute(Object_& object) {

	}
	//===================================================================================
	void EnterCommand::execute() {
		buttonPush = true;
	}
	void EnterCommand::execute(Object_& object) {

	}
	//===================================================================================

	void ESCCommand::execute() {
		buttonPush = true;
	}
	void ESCCommand::execute(Object_& object) {

	}
}