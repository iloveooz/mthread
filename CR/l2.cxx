
	#include <iostream>
	#include <unistd.h>

	#include <vector>

	#include <mutex>
	#include <thread>

	int N = 0;
	
	struct Line {
		Line (std::string name, std::string surname, int year) :
			name(name),
			surname(surname),
			year(year)
		{}
		std::string name;
		std::string surname;
		int year;
	};

	 /*	Если не использовать мьютексы отображение и 
		модификация данных будут не верными */

	void foo (std::vector <Line> &db, std::mutex& mtx) {
		while (1) {
			std::lock_guard<std::mutex> lock (mtx);
			//Transactions beginning
			// mtx.lock();

			db.at(0).year = 2000;
			db.at(1).year = 2000;
			db.at(2).year = 2000;
			db.at(3).year = 2000;
			db.at(4).year = 2000;

			//The end of the transaction
			// mtx.unlock();
		}
	}

	void bar (std::vector<Line>& db, std::mutex& mtx) {
		while (1) {
			std::lock_guard<std::mutex> lock (mtx);
			//Transactions beginning
			// mtx.lock();

			db.at(0).year = 1856;
			db.at(1).year = 1879;
			db.at(2).year = 1955;
			db.at(3).year = 1955;
			db.at(4).year = 1984;

			//The end of the transaction
			// mtx.unlock();
		}
	}

	void buz (std::vector<Line>& db, std::mutex& mtx) {
		while (1) {
			std::lock_guard<std::mutex> lock (mtx);
			//Transactions beginning
			// mtx.lock();

			db.at(0).year = 10;
			db.at(1).year = 20;
			db.at(2).year = 30;
			db.at(3).year = 40;
			db.at(4).year = 50;

			//The end of the transaction
			// mtx.unlock();
		}
	}

	void view (std::vector<Line>& db, std::mutex& mtx) {
		while (1) {
			std::lock_guard<std::mutex> lock (mtx);

			std::cout << N << " Viev: ";
			for (auto row : db)	{ 
				std::cout << row.year << ", ";	
			} 
			N++;
			std::cout << '\n';
			usleep(50000);
		}
	}

	int main () {
		std::vector<Line> db;
		db.push_back(Line("Nikola", "Tesla", 1856));
		db.push_back(Line("Albert", "Einstein", 1879));
		db.push_back(Line("Bill", "Gates", 1955));
		db.push_back(Line("Stive", "Jobs", 1955));
		db.push_back(Line("Mark", "Zuckerberg", 1984));

		std::mutex mtx;

		std::thread t1 (foo, std::ref(db), std::ref(mtx));
		std::thread t2 (bar, std::ref(db), std::ref(mtx));
		std::thread t3 (buz, std::ref(db), std::ref(mtx));
		
		std::thread t4 (view, std::ref(db), std::ref(mtx));

		t1.detach();
		t2.detach();
		t3.join();
	}
