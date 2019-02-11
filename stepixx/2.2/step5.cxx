
	#include <iostream>
	#include <memory>
	
	class Foo {};
	
	int main() {
		// std::auto_ptr <Foo> sp1(new Foo());
		// std::auto_ptr <Foo> sp2;
		
		// sp2 = sp1;
		
		std::unique_ptr <Foo> up1(new Foo());
		std::unique_ptr <Foo> up2;
		
		up2 = std::move(up1);
		
		up2.reset();
		up2.reset();
		up1.reset();
		
		
		
		return 0;
	}
