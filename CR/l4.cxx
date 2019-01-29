	#include <iostream>
	#include <unistd.h>

	#include <thread>
	#include <future>

	bool task (int n) {
		sleep(n);
		std::cout << n << ": ";
		return true;
	}

	void task_f (std::future<int>& f) {
		int n = f.get();
		sleep(n);
		std::cout << n << ": " << "DONE" << std::endl;
	}

	int main () {
		//Create thread and wait return value
		{
			std::future<bool> ft = std::async(task, 3);

			if (ft.get()) {
				std::cout << "DONE 1" << std::endl;
			}
		}

		//Create thread and wait return value
		{
			std::packaged_task<bool(int)> tsk (task);
			std::future<bool> ret = tsk.get_future();

			std::thread th (move(tsk), 2);

			if (ret.get()) {
				std::cout << "DONE 2" << std::endl;
			}

			th.join();
		}

		//Self set return std::future value
		{
			std::promise<int> prom;
			std::future<int> ft = prom.get_future();

			std::thread t1 (task_f, ref(ft));

			prom.set_value(1);

			t1.join();
		}
	}
