
	#include <iostream>
	
	int main() {
		
		uint32_t *i = (uint32_t*) 1024;
		i++;
		
		std::cout << *i << std::endl;
		
		return 0;
	}
