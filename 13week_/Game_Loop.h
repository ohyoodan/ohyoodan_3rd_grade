#pragma once
using namespace std;
namespace GameEngine {

	class GameLoop {

		bool start = false;
		int score = 0;

		enum state {
		Title,
		};

		public: GameLoop() {

		}
		public:~GameLoop() {

		}

		void start_L() {
			init();

			while (1) {
				auto t0 = std::chrono::system_clock::now();
				Input();
				Update();
				Render();
				auto t1 = std::chrono::system_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
				std::cout << "Took" << duration << "milliseconds" << std::endl;
			}

		}

		void init() {
			
			

		}

		void Update() {


		}

		void Render() {
			
		}
		
		void Input() {

		}


	};


}