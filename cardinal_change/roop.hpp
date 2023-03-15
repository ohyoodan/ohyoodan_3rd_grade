#pragma once

#include<conio.h>
#include <Windows.h>
#include <vector>
#include <sstream>
#include <string>
#include <thread>

namespace cardinal_change {


	class cardinal_change_Loop {
		bool output = false;//���� ������ �ȳ����� �Ǵ�
		bool start = false;// ó�� ���� �Ǵ�
		std::vector<int> numinput; //�Է� �����ڷ�
		std::string str; //�ӽ� �Է�
		std::string outcardinal;// ��� �����ڷ�
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
				  
		  }
		  void Input() {
			  if (start) {//ó������ �������� �ʴ´�.				 

					  /*if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
						 // ����
						  change_Running = false;
						  //������ ��ߵǴ� ��
					  }*/
				  std::cin >> str;//���ڸ� �ް� ���� �� ��
				  }
				  
			  
		  }

		  void Update() {
			  output = false;
			  if (start) {
				  chack();
				  change();
				  
				  for (const auto& num : numinput) { //���ڸ� �θ� ���ڷ� + if������ �߰��� ��
					  outcardinal = to_roman(num);
				  }
				  
			  }


		  }

		  void Render() {
			  if (output) {//��� ��� num->cardinal
				  std::cout << "�θ�����:" ;
				  
				  std::cout << outcardinal << " "<<std::endl;
				  
				  std::cout << std::endl;
			  }
			  start = true;
			  if (!oryu) {// ������ �ƴϸ� ����
				  std::cout << "�θ����ڷ� ������ ���ڸ� �Է����ּ���." << std::endl;
				  std::cout << "ESCŰ�� ������ �����մϴ�." << std::endl;
				  std::cout << "�Է�:" ;
			  }
			  else {
				  std::cout << "���� �߻� ����" << std::endl;
				  change_Running = false;
			  }
		  }
		  void Release() {

		  }
		  void chack() {//��� ���� �Ǻ� �̱���
			  numinput.clear();

			  if (std::isdigit(str[0])) {
				  //�Է� ���� ���� �� ��
				  num_cardinal = true;
				  cardinal_num = false;
			  }
			  else {
				  num_cardinal = false;
				  cardinal_num = true;
			  }
		  }

		  void change() {//���ڿ�>> ��� ��ȯ��
			  std::istringstream iss(str);//���ڿ��� �и��� �ǹ��ִ� �����ͷ� ��ȯ�ϴ� ���̺귯��
			  int num;
			  iss >> num;//��ȯ 
			  numinput.push_back(num);//�ڷ� ������ �ֱ�
			  output = true;
			  			 
		  }
		  std::string to_roman(int num) {//���>�θ����� ��ȯ�� - ����и�
			  std::string result;
			  const int values[] = {//������ �ʴ� �迭
				  1000, 900, 500, 400,
				  100, 90, 50, 40,
				  10, 9, 5, 4,
				  1
			  };
			  const std::string symbols[] = {//������ �ʴ� �迭
				  "M", "CM", "D", "CD",
				  "C", "XC", "L", "XL",
				  "X", "IX", "V", "IV",
				  "I"
			  };
			  for (int i = 0; i < 13; ++i) {
				  while (num >= values[i]) {
					  num -= values[i];
					  result += symbols[i];
				  }
			  }
			  return result;
		  }

		  
		  int roman_to_int(const std::string& s)// �θ� ���ڸ� ���ڷ� �ٲٴ� �Լ� -����и�
		  {
			  
			  int roman_values[] = { 1, 5, 10, 50, 100, 500, 1000 };
			  char roman_chars[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

			  int result = 0;
			  int prev_value = 0;

			  
			  for (int i = s.size() - 1; i >= 0; --i) {// ���ڿ� ���������� �� ���ڸ� ó��
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
	};



	

}