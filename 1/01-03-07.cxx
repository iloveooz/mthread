
	#include <iostream>

	int & f(int &a, int &b) {
		return (a > b) ? a : b; 
	}

	int main() {
		int d[] = { 0, 1, 2, 3, 4 };
		int a = 5, b = 7;
		3[d] = f(a, b) = 0 > a ? a : b;
		for (auto Cnt = 0; Cnt < sizeof(d) / sizeof(int); std::cout << Cnt++[d] << "   ");

		return 0;
	}
