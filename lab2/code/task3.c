
#include <stdio.h> 
#include <stdlib.h>
int globalUninitialized; 
int globalInitialized = 5;
int main() {
	int i;
	printf("The stack top is near %p\n", &i);
	i = 5;
	int* ip = malloc(sizeof(i));
	printf("The bss segment is near %p\n", &globalUninitialized); 
	printf("The data segment is near %p\n", &globalInitialized); 
	printf("The heap segment is near %p\n", ip);
	return 0;
}