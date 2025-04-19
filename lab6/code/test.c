#include <stdio.h>

int main() {
	int x;
	printf("%d", x); // Uninitialized read!
	return 0;
}
