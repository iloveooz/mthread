
	#include <stdio.h>
	#include <stdlib.h>
	
	int main(int argc, char **argv) {
		for (unsigned int i = 0; i < 100; i++) {
			int *x = (int *)malloc(sizeof(int));
			*x = 123;
		}
		
	}
