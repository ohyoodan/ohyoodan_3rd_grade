#pragma once




namespace cardinal_change {


	class cardinal_change_Loop {


	public: 
		bool change_Running = false;
		cardinal_change_Loop() {};
		  ~cardinal_change_Loop()
		  {

		  };

		  void Run() {
			  change_Running = true;
			  Init();
			  while (change_Running) {
				  Input();
				  Update();
				  Render();
			  }
			  Release();
		  }

		  void Init() {

		  }
		  void Input() {
			  
		  }

		  void Update() {

		  }

		  void Render() {

		  }
		  void Release() {

		  }
	};



	

}