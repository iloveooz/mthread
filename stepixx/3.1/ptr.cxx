
	#include <iostream>
	
	int main(int argc, char **argv) {
		int iValue = 777;
		double dValue = 888.888;
		float fValue = 44.44;
		
		void *vptr = &iValue;
		void *vptr2 = &dValue;
		void *vptr3 = &fValue;
		
		int *iptr = static_cast <int *> (vptr);
		double *dptr = static_cast <double *> (vptr2);
		float *fptr = static_cast <float *> (vptr3);
		
		std::cout << *iptr << '\n'; 
		std::cout << *dptr << '\n'; 
		std::cout << *fptr << '\n'; 
		
		return 0;
	}
