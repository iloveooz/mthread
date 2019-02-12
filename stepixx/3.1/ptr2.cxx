
	#include <iostream>
	
	enum Type {
		INT,
		DOUBLE,
		CSTRING
	};
	
	void printValue (void *ptr, Type type) {
		switch (type) {
			case INT:
				// конвертируем в указатель типа int и разыменовываем
				std::cout << *static_cast <int *> (ptr) << '\n';
				break;
			case DOUBLE:
				// конвертируем в указатель типа double и разыменовываем
				std::cout << *static_cast <double *> (ptr) << '\n';
				break;
			case CSTRING:
				std::cout << static_cast <char *> (ptr) << '\n';
				break;
		}
	}
		
	int main(int argc, char ** argv) {
		int iValue = 7;
		double dValue = 555.555;
		char cString[] = "BUGAGA";
		
		printValue(&iValue, INT);
		printValue(&dValue, DOUBLE);
		printValue(cString, CSTRING);
		
		return 0;
	}
