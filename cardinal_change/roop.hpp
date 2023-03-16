#pragma once

#include <conio.h>
#include <Windows.h>
#include <vector>
#include <sstream>
#include <string>
#include <thread>
#include <chrono>

namespace cardinal_change {
	

	class cardinal_change_Loop {
		bool output = false;//값이 나올지 안나올지 판단
		bool start = false;// 처음 실행 판단
		std::vector<int> numinput; //입력 자료구조
		std::string str; //임시 입력
		std::string outcardinal;// 출력 자료구조 num->cardnal
		int outint;//출력 자료구조 cardinal->num
		bool oryu = false; //오류 
		bool num_cardinal = false;// num-> cardinal
		bool cardinal_num = false;// cardinal -> num
		
		
	public: 
		bool change_Running = false;
		cardinal_change_Loop() {};
		  ~cardinal_change_Loop(){};
		 
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
			  std::thread t1(&cardinal_change::cardinal_change_Loop::Exit, this);
			  t1.detach();
			
		  }
		  void Input() {
			  if (start) {//처음에는 실행하지 않는다.				 

				  /*if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
					 // 종료
					  change_Running = false;
					  //스레드 써야되는 듯
				  }*/
				  std::cin >> str;

			  }
			  
		  }

		  void Update() {
			  output = false;
			  if (start) {
				  chack(str);
				  change();
				  if (num_cardinal) {
					  for (const auto& num : numinput) { //숫자를 로마 숫자로 + if문으로 추가할 것
						  outcardinal = to_roman(num);
					  }
				  }else if(cardinal_num){
					  outint = roman_to_int(str);

				  }
			  }


		  }

		  void Render() {
			  if (output&&oryu==false) {//결과 출력 num->cardinal
				  if (num_cardinal) {
					  std::cout << "로마숫자:";

					  std::cout << outcardinal << " " << std::endl;

					  std::cout << std::endl;


				  }
				  else if(cardinal_num&&oryu==false) {
					  std::cout << "숫자:";

					  std::cout << outint<<" "<< std::endl;

					  std::cout << std::endl;
				  }
				  
			  }
			  start = true;
			  if (oryu==false) {// 오류가 아니면 실행
				  std::cout << "로마숫자 or 숫자를 입력해주세요." << std::endl;
				  std::cout << "ESC키를 누르면 종료합니다." << std::endl;
				  std::cout << "입력:" ;
			  }else if(oryu){
				  std::cout << "오류 발생 종료" << std::endl;
				  change_Running = false;
			  }
		  }
		  void Release() {

		  }
		  void chack(std::string s) {
			  numinput.clear();

			  bool nu = false;
			 for(const auto& ch: str)
			  if (std::isdigit(ch)) {
				  //입력 값이 숫자 일 때
				  num_cardinal = true;
				  cardinal_num = false;
				  nu = true;
			  }
			  else {//입력 값이 문자 일 때
				  num_cardinal = false;
				  cardinal_num = true;
			  }
			 
		  }

		  void change() {//문자열>> 상수 변환기
			
			  if (num_cardinal) {
				  std::istringstream iss(str);//문자열을 분리해 의미있는 데이터로 변환하는 라이브러리
				  int num;
				  iss >> num;//변환 
				  numinput.push_back(num);//자료 구조에 넣기
				  output = true;
			  }
			  else if (cardinal_num) {
				  output = true;
			  }
			  
			  			 
		  }
		  std::string to_roman(int num) {//상수>로마숫자 변환기 - 
			  
			  int values[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
			  std::string numerals[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
			  std::string result;

			  // 큰 값부터 작은 값 순서대로 처리
			  for (int i = 12; i >= 0; --i) {
				  // 현재 값이 남아있는 동안 처리
				  while (num >= values[i]) {
					  num -= values[i];
					  result += numerals[i];
				  }
			  }

			  return result;
		  }

		  bool is_valid_roman_numeral(const std::string& s)//로마숫자 유효성 검사
		  {
			  
			  
			  std::string valid_chars = "IVXLCDM";
			  for (char c : s) {
				  if (valid_chars.find(c) == std::string::npos) {
					  return false;
				  }
			  }
			  return true;
		  }
		  
		  int roman_to_int(const std::string& s)// 로마 숫자를 숫자로 바꾸는 함수 
		  {
			  // 입력된 로마 숫자가 유효한지 검증함
			  if (!is_valid_roman_numeral(s)) {
				  oryu = true;
				  return -1;// 오류
			  }

			  int roman_values[] = { 1, 5, 10, 50, 100, 500, 1000 };
			  char roman_chars[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

			  int result = 0;
			  int prev_value = 0;

			  
			  for (int i = s.size() - 1; i >= 0; --i) {// 문자열 끝에서부터 각 문자를 처리하고
				  char c = s[i];

				  // 현재 문자에 대한 숫자 값을 배열에서 찾음
				  int value = 0;
				  for (int j = 0; j < 7; ++j) {
					  if (roman_chars[j] == c) {
						  value = roman_values[j];
						  break;
					  }
				  }

				  
				  if (value >= prev_value) {// 현재 문자가 이전 문자보다 크면 더해주고, 작으면 빼줌
					  result += value;
				  }
				  else {
					  result -= value;
				  }

				  prev_value = value;
			  }

			  return result;
		  }
		  void Exit() {
			 
			  while (1) {
				  if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
					  change_Running = false;
					  std::terminate();
					  // 종료			
					  break;
				  }
			  }
		  }
		  


		  
	};



	

}