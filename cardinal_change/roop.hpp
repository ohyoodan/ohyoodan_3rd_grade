#pragma once

#include<conio.h>
#include <Windows.h>
#include <vector>
#include <sstream>
#include <string>
namespace cardinal_change {


	class cardinal_change_Loop {
		bool output = false;//���� ������ �ȳ����� �Ǵ�
		bool start = false;// ó�� ���� �Ǵ�
		std::vector<int> Test; //�Է� �����ڷ�
		std::string str; //�ӽ� �Է�
		std::string outcardinal;// ��� �����ڷ�
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
				  
				  
				  
				  
				  
				  
			  }


		  }

		  void Render() {
			  if (output) {//��� ���
				  std::cout << "�θ�����:" ;
				  for (const auto& n : Test) {
					  std::cout << n << " "<<std::endl;
				  }
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
		  void chack() {
			  Test.clear();
			  if (str.empty() || (str.length() == 1 && !isdigit(str[0]))) {//���ڿ� ��� ���� ��� false
				  //��ȯ false
			}
			  for (char c : str) {//���ڿ��� ��������?
				  if (!isdigit(c)) {
					  //��ȯ  false
				  }
			  }
		  }

		  void change() {
			  std::istringstream iss(str);//���ڿ��� �и��� �ǹ��ִ� �����ͷ� ��ȯ�ϴ� ���̺귯��
			  int num;
			  iss >> num;//��ȯ 
			  Test.push_back(num);//�ڷ� ������ �ֱ�
			  output = true;
			  switch (1)
			  {
			  default:
				  break;
			  }


		  }
	};



	

}