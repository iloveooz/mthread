	
	#include <iostream>
	
	// поиск производной
	std::string derivative(std::string polynomial) {
		std::string DER = "";
		
		return (std::string) DER;
	}
	
	std::string generator(int number) {
		std::string FUNC = "";
		std::string fragment = "";
		
		for (int i = 0; i < number; i++) {
			// определяем знак
			if (rand() % 2) 
				fragment += "-";
			// определяем префиксное число
			if (rand() % 5) {
				switch (rand() % 5) {
					case 1: fragment += "2"; break;
					case 2: fragment += "3"; break;
					case 3: fragment += "4"; break;
					case 4: fragment += "5"; break;
				}
			}
			// вставляем х
			if (rand() % 3)
				fragment += "x";
			// определяем степень
			if (rand() % 5) {
				switch (rand() % 5) {
					case 1: fragment += "^10"; break;
					case 2: fragment += "^30"; break;
					case 3: fragment += "^45"; break;
					case 4: fragment += "^55"; break;
				}
			}
			if (i < number - 1)
				fragment += "+";
		}
		
		FUNC = fragment;
		
		return (std::string) FUNC;
	}
	
	int main() {
		
		srand(time(0));
		
		int number = 0;
		std::string derivate = "";
		std::string function = "";
		
		std::cout << "Сколько членов в функции хотите? - ";
		std::cin >> number;
		
		function = generator(number);
		
		std::cout << function << '\n';
		
		return 0;
	}
