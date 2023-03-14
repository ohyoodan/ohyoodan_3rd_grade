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
				 // chack();
				  change();
				  for (const auto& num : numinput) {
					  outcardinal = to_roman(num);
				  }
				  
				  
				  
				  
				  
			  }


		  }

		  void Render() {
			  if (output) {//��� ���
				  std::cout << "�θ�����:" ;
				  
					  std::cout << outcardinal << " "<<std::endl;
				  
				  std::cout << std::endl;
			  }
			  start = true;
			  if (!oryu) {
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
			  if (str.empty() || (str.length() == 1 && !isdigit(str[0]))) {//���ڿ� ��� ���� ��� false
				  //��ȯ false
			}
			  for (char c : str) {//���ڿ��� ��������?
				  if (!isdigit(c)) {
					  //��ȯ  false
				  }
			  }
		  }

		  void change() {//���ڿ�>> ��� ��ȯ��
			  std::istringstream iss(str);//���ڿ��� �и��� �ǹ��ִ� �����ͷ� ��ȯ�ϴ� ���̺귯��
			  int num;
			  iss >> num;//��ȯ 
			  numinput.push_back(num);//�ڷ� ������ �ֱ�
			  output = true;
			  
			 
		  }
		  std::string to_roman(int num) {//���>�θ����� ��ȯ��
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

		 
	};



	

}