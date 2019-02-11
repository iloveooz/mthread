	
	#include <iostream>
	
	template <class Type>
	class SmartPointer {
	private:
		Type* pointer;
	
	public:
		// конструктор
		SmartPointer(Type *p) : pointer(p) {}
		
		// оператор звёздочка
		operator Type* () { 
			return pointer;
		}
		
		// оператор стрелочка
		Type* operator-> () {
			if (!pointer) {
				pointer = new Type();
				std::cerr << "Bad pointer!" << '\n';
			}
			return pointer;
		}
		
		// вычитание "умных" указателей
		std::ptrdiff_t operator -(SmartPointer <Type> p) {
			return pointer - p.pointer;
		}
		
		// вычитание "глупого" указателя из "умного"
		std::ptrdiff_t operator -(void *p) {
			return pointer - p;
		}		
		
	};
	
	class Foo {
	private:
		int a, b;
	public:
		Foo() : a(0), b(0) {}
		Foo(int a, int b) : a(a), b(b) {}
		
		int Sum() {
			return a + b;
		}
		
	};
	
	
	int main(int argc, char ** argv ) {
		SmartPointer <Foo> sp = new Foo(2, 2);
		
		SmartPointer <Foo> np(NULL);
		
		std::cout << sp->Sum() << '\n';
		std::cout << np->Sum() << '\n';
		
		return 0;
	}
	
