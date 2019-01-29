
	#include <vector>
	#include <iostream>
	#include <mutex>
	#include <thread>
	
	#include <unistd.h> // usleep function

	int N = 0;
	
	void foo(int &num, std::mutex& mtx) {
		while (1) {
			// mtx.lock();
			num += 2;
			N++;
			std::cout << "FOO: " << num << ' ' << N << '\n';
			mtx.unlock();
			
			usleep(50000);
		}
	}

	void bar(int &num, std::mutex& mtx) {
		while (1) {
			mtx.lock();
			num -= 2;
			N++;
			std::cout << "BAR: " << num << ' ' << N << '\n';
			// mtx.unlock();
			
			usleep(50000);
		}
	}
	

	int main() {
		int num = 10;
		std::mutex mtx;
		
		std::thread P1(foo, std::ref(num), std::ref(mtx));
		std::thread P2(bar, std::ref(num), std::ref(mtx));
		
		P1.join();
		P2.join();
		
		return EXIT_SUCCESS;
	}
		
