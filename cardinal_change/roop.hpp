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
		bool output = false;//���� ������ �ȳ����� �Ǵ�
		bool start = false;// ó�� ���� �Ǵ�
		std::vector<int> numinput; //�Է� �ڷᱸ��
		std::string str; //�ӽ� �Է�
		std::string outcardinal;// ��� �ڷᱸ�� num->cardnal
		int outint;//��� �ڷᱸ�� cardinal->num
		bool oryu = false; //���� 
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
			  if (start) {//ó������ �������� �ʴ´�.				 

				  /*if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
					 // ����
					  change_Running = false;
					  //������ ��ߵǴ� ��
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
					  for (const auto& num : numinput) { //���ڸ� �θ� ���ڷ� + if������ �߰��� ��
						  outcardinal = to_roman(num);
					  }
				  }else if(cardinal_num){
					  outint = roman_to_int(str);

				  }
			  }


		  }

		  void Render() {
			  if (output&&oryu==false) {//��� ��� num->cardinal
				  if (num_cardinal) {
					  std::cout << "�θ�����:";

					  std::cout << outcardinal << " " << std::endl;

					  std::cout << std::endl;


				  }
				  else if(cardinal_num&&oryu==false) {
					  std::cout << "����:";

					  std::cout << outint<<" "<< std::endl;

					  std::cout << std::endl;
				  }
				  
			  }
			  start = true;
			  if (oryu==false) {// ������ �ƴϸ� ����
				  std::cout << "�θ����� or ���ڸ� �Է����ּ���." << std::endl;
				  std::cout << "ESCŰ�� ������ �����մϴ�." << std::endl;
				  std::cout << "�Է�:" ;
			  }else if(oryu){
				  std::cout << "���� �߻� ����" << std::endl;
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
				  //�Է� ���� ���� �� ��
				  num_cardinal = true;
				  cardinal_num = false;
				  nu = true;
			  }
			  else {//�Է� ���� ���� �� ��
				  num_cardinal = false;
				  cardinal_num = true;
			  }
			 
		  }

		  void change() {//���ڿ�>> ��� ��ȯ��
			
			  if (num_cardinal) {
				  std::istringstream iss(str);//���ڿ��� �и��� �ǹ��ִ� �����ͷ� ��ȯ�ϴ� ���̺귯��
				  int num;
				  iss >> num;//��ȯ 
				  numinput.push_back(num);//�ڷ� ������ �ֱ�
				  output = true;
			  }
			  else if (cardinal_num) {
				  output = true;
			  }
			  
			  			 
		  }
		  std::string to_roman(int num) {//���>�θ����� ��ȯ�� - 
			  
			  int values[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
			  std::string numerals[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
			  std::string result;

			  // ū ������ ���� �� ������� ó��
			  for (int i = 12; i >= 0; --i) {
				  // ���� ���� �����ִ� ���� ó��
				  while (num >= values[i]) {
					  num -= values[i];
					  result += numerals[i];
				  }
			  }

			  return result;
		  }

		  bool is_valid_roman_numeral(const std::string& s)//�θ����� ��ȿ�� �˻�
		  {
			  
			  
			  std::string valid_chars = "IVXLCDM";
			  for (char c : s) {
				  if (valid_chars.find(c) == std::string::npos) {
					  return false;
				  }
			  }
			  return true;
		  }
		  
		  int roman_to_int(const std::string& s)// �θ� ���ڸ� ���ڷ� �ٲٴ� �Լ� 
		  {
			  // �Էµ� �θ� ���ڰ� ��ȿ���� ������
			  if (!is_valid_roman_numeral(s)) {
				  oryu = true;
				  return -1;// ����
			  }

			  int roman_values[] = { 1, 5, 10, 50, 100, 500, 1000 };
			  char roman_chars[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

			  int result = 0;
			  int prev_value = 0;

			  
			  for (int i = s.size() - 1; i >= 0; --i) {// ���ڿ� ���������� �� ���ڸ� ó���ϰ�
				  char c = s[i];

				  // ���� ���ڿ� ���� ���� ���� �迭���� ã��
				  int value = 0;
				  for (int j = 0; j < 7; ++j) {
					  if (roman_chars[j] == c) {
						  value = roman_values[j];
						  break;
					  }
				  }

				  
				  if (value >= prev_value) {// ���� ���ڰ� ���� ���ں��� ũ�� �����ְ�, ������ ����
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
					  // ����			
					  break;
				  }
			  }
		  }
		  


		  
	};



	

}