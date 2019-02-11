
	#include <iostream>
	
	template <class Type>
	class StringPointer {
	public:
		// конструктор
		StringPointer (Type* Pointer) : pointer(Pointer), extraAlloc(false) {
			if (Pointer == nullptr) {
				extraAlloc = true;
				pointer = new std::string;
			}
			std::cout << "Сработал конструктор." << '\n';
		}
		
		// оператор-стрелочка
		Type* operator -> () {
			return pointer;
		}
		
		// operator std::string* () {}
		Type& operator * () {
			return *pointer;
		}
		
		// деструктор
		~StringPointer () {
			if (extraAlloc) 
				delete pointer;
			std::cout << "Сработал деструктор." << '\n';
		}
	protected:
		// empty
	private:
		Type* pointer;
		bool extraAlloc;
	};

	int main(int argc, char **argv) {
		std::string s1 = "almost string";
		
		StringPointer <std::string> sp1(&s1);
		StringPointer <std::string> sp2(NULL);
		
		std::cout << "Длина: " << sp1->length() << '\n';
		std::cout << "Строка: " << *sp1 << '\n';

		std::cout << "Длина: " << sp2->length() << '\n';
		std::cout << "Строка: " << *sp2 << '\n';

		return 0;
	}
