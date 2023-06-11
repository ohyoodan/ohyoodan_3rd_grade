#include "InputHandle.h"


namespace GameEngine {

	InputHandle::InputHandle(Button_state b_state):button_state(b_state){
		command[0] = new UpCommand();//À§
		command[1] = new DownCommand();//¾Æ
		command[2] = new LeftCommand();//¿Þ
		command[3] = new RightCommand();//¿À
		command[4] = new EnterCommand();//¿£
		command[5] = new ESCCommand();//ESC
		
	}
	InputHandle::~InputHandle() {
		for (size_t i = 0; i <6; i++) {
			delete(command[i]);
		}

	}
	int InputHandle::KeyCheck() {
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			if(button_state.Up == true) {
				command[0]->execute();
				Sleep(100);
				command[0]->ButtonSet(false);
				return 1;
			}
			return 0;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			if (button_state.Down == true) {
				command[1]->execute();
				Sleep(100);
				command[1]->ButtonSet(false);
				return 2;
			}
			return 0;
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if (button_state.Left == true) {
				command[2]->execute();
				Sleep(100);
				command[2]->ButtonSet(false);
				return 3;
			}
			return 0;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			if (button_state.Right == true) {
				command[3]->execute();
				Sleep(100);
				command[3]->ButtonSet(false);
				return 4;
			}
			return 0;
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			if (button_state.Enter == true) {
				command[4]->execute();
				Sleep(100);
				command[4]->ButtonSet(false);
				return 5;
			}
			return 0;
		}
		else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			if (button_state.ESC == true) {
				command[5]->execute();
				Sleep(100);
				command[5]->ButtonSet(false);
				return 6;
			}
			return 0;
		}
		else {
			return 0;
		}
	}

	void InputHandle::button_set(Button_state b_state) {
		button_state = b_state;
	}

	
}