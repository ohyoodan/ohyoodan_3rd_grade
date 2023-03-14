#pragma once

#include<conio.h>
#include <Windows.h>
#include <vector>
#include <sstream>
#include <string>
namespace cardinal_change {


	class cardinal_change_Loop {
		bool output = false;//값이 나올지 안나올지 판단
		bool start = false;// 처음 실행 판단
		std::vector<int> Test; //입력 구조자료
		std::string str; //임시 입력
		std::string outcardinal;// 출력 구조자료
		bool oryu = false;
		
	public: 
		bool change_Running = false;
		cardinal_change_Loop() {};
		  ~cardinal_change_Loop()
		  {};

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
			  if (start) {//처음에는 실행하지 않는다.				 

					  /*if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
						 // 종료
						  change_Running = false;
						  //스레드 써야되는 듯
					  }*/
				  
				  
				  std::cin >> str;//숫자만 받게 설계 할 것
				  }
				  
			  
		  }

		  void Update() {
			  output = false;
			  if (start) {
				  chack();
				  
				  
				  
				  
				  
				  
			  }


		  }

		  void Render() {
			  if (output) {//결과 출력
				  std::cout << "로마숫자:" ;
				  for (const auto& n : Test) {
					  std::cout << n << " "<<std::endl;
				  }
				  std::cout << std::endl;
			  }
			  start = true;
			  if (!oryu) {
				  std::cout << "로마숫자로 변경할 숫자를 입력해주세요." << std::endl;
				  std::cout << "ESC키를 누르면 종료합니다." << std::endl;
				  std::cout << "입력:" ;
			  }
			  else {
				  std::cout << "오류 발생 종료" << std::endl;
				  change_Running = false;
			  }
		  }
		  void Release() {

		  }
		  void chack() {
			  Test.clear();
			  if (str.empty() || (str.length() == 1 && !isdigit(str[0]))) {//문자열 비어 있을 경우 false
				  //반환 false
			}
			  for (char c : str) {//문자열이 숫자인지?
				  if (!isdigit(c)) {
					  //반환  false
				  }
			  }
		  }

		  void change() {
			  std::istringstream iss(str);//문자열을 분리해 의미있는 데이터로 변환하는 라이브러리
			  int num;
			  iss >> num;//변환 
			  Test.push_back(num);//자료 구조에 넣기
			  output = true;
			  switch (1)
			  {
			  default:
				  break;
			  }


		  }
	};



	

}