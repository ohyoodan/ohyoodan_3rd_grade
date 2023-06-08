#pragma once
#include "Scene.h"
#include "GameEnum.h"

namespace GameEngine {
	class SceneHandle
	{
	private:
		

		Scene* scene;

		state Gamestate;
	public :
		SceneHandle();
		~SceneHandle();
		
	void ChangeScene();




	};
}

