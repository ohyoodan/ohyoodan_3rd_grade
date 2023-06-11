#pragma once
#include "Command.h"
#include <algorithm>
#include "GameEnum.h"

namespace GameEngine {
	class InputHandle
	{private:
		Command* command[6];
		Button_state button_state;


	public: InputHandle(Button_state b_state);
		  ~InputHandle();

		  int KeyCheck();

		  void button_set(Button_state b_state);
	};

}