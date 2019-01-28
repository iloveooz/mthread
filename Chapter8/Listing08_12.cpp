	#include <iostream>
	#include <cstdlib>
	#include <string>
	#include <thread>
	#include <chrono>
	#include <mutex>
	
	std::mutex m;
	
	// Функция для создания потоков:
	void mythread(std::string name, int time, int steps) {
	   for(int k = 1; k <= steps; k++) {
		  // Временная задержка в выполнении команд:
		  std::this_thread::sleep_for(std::chrono::seconds(time));
		  
		  // Блокировка доступа к ресурсу (консоли):
		  m.lock();
		  
		  // Отображение сообщения в консоли:
		  std::cout << "Поток " << name << " (" << std::this_thread::get_id() << ")" << ":\tсообщение " << k << '\n';
		  
		  // Разблокировка ресурса (консоли):
		  m.unlock();
	   }
	}
	
	int main(){
	   // Количество циклов в потоках:
	   int n = 5;
	   
	   std::cout << "Hardware_concurrency " << std::thread::hardware_concurrency() << '\n';
	   
	   std::cout << "Запускаются потоки...\n";
	   
	   // Первый дочерний поток:
	   std::thread A(mythread, "Alpha" , 4, n);
	   
	   // Второй дочерний поток:
	   std::thread B(mythread, "Bravo", 3, n);
	   
	   // Вызов функции в главном потоке:
	   mythread("Main",2,n);
	   
	   // Ожидание завершения первого дочернего потока:
	   if(A.joinable()){
		  A.join();
	   }
	   
	   // Ожидание завершения второго дочернего потока:
	   if(B.joinable()){
		  B.join();
	   }
	   
	   std::cout << "Выполнение программы завершено...\n";

	   return 0;
	}

