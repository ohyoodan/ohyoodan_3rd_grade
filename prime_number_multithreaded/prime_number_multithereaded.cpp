#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <memory>
#include <mutex>
#include <conio.h>
#include <Windows.h>


using namespace std;
const int MaxCount = 150000;
const int ThreadCount = 4;


bool IsPrimeNumber(int number) {
	if (number == 1) {
		return false;
	}
	if (number == 2 || number == 3) {
		return true;
	}
	for (int i = 2; i < number - 1; i++) {
		if ((number % i) == 0) {
			return false;
		}
	}
	return true;

}

void PrintNumbers(const vector<int>& primes) {
	for (int v : primes) {
		cout << v << endl;
	}
}

void main() {

	//스레드는 여기서 값을 꺼내온다.
	int num = 1;
	recursive_mutex num_mutex;

	vector<int>primes;
	recursive_mutex primes_mutex;

	auto t0 = chrono::system_clock::now();

	vector<shared_ptr<thread>>threads;

	for (int i = 0; i < ThreadCount; i++) {

		shared_ptr<thread> thread(new std::thread([&]() {
			while (true)
			{
				int n;
				{
					lock_guard<recursive_mutex>num_lock(num_mutex);
					n = num;
					num++;
				}
				if (n >= MaxCount) {
					break;
				}
				if (IsPrimeNumber(n)) {
					lock_guard<recursive_mutex>primes_lock(primes_mutex);
					Sleep(1);
					primes.push_back(n);
				}
			}
		}));
		threads.push_back(thread);
	}

	//모든 스레드가 일을 마칠 때까지 기다린다.
	for (auto& thread : threads) {
		thread->join();
	}
	//끝
	
	auto t1 = chrono::system_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(t1 - t0).count();
	cout << "Took" << duration << "milliseconds" << endl;

	//PrintNumbers(primes);
}