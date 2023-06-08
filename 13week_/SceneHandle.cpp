#include "SceneHandle.h"



namespace GameEngine {

	//dynamic_cast
	//https://blockdmask.tistory.com/241?category=249597
	SceneHandle::SceneHandle() {
		scene = new Scene();
		
	}
	SceneHandle::~SceneHandle() {		
		delete scene;
	}
	
	void SceneHandle::ChangeScene() {
		delete scene;
		scene = new Title_();
	}

}