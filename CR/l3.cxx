	#include <iostream>
	#include <fstream>
	#include <unistd.h>

	#include <mutex>
	#include <thread>
	#include <condition_variable>

	std::mutex mtx;
	std::condition_variable cv;

	bool _var = false;
	
	bool ret () { 
		return _var;
	}

	void foo () {
		std::ofstream log;
		std::string str;
		
		static int numFoo = 0;

		while (true) {
			std::unique_lock<std::mutex> ulm (mtx);
			cv.wait(ulm, ret);

			log.open("log.log", std::ios_base::app);
				str = "Is Foo: " + std::to_string(++numFoo) + '\n';
				log.write(str.c_str(), str.length());
			log.close();

			usleep(500000);
		}
	}

	void bar () {
		while (true) {
			char input;

			std::cout << "Input: "; 
			std::cin >> input;
			std::cin.clear();

			if (input == 'y') {
				_var = true;
				cv.notify_one();
			}

			if (input == 'n')
				_var = false;
		}
	}

	int main ()	{
		std::thread t1 (bar);
		std::thread t2 (foo);

		t1.detach();
		t2.join();
	}
