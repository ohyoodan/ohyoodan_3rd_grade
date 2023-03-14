#pragma once
#include "Command.hpp"


class EseKey : public cardinal_change::Command{
public:
	void Exit() {
		std::cout << "Á¾·á";
	}
};