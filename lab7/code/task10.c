
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	float n;
	int i;
	srand((unsigned int)time(NULL));
	printf("Enter 'n' (number): ");
	if (scanf("%f", &n) != 1) {
		fprintf(stderr, "ERROR: wrong input !\n");
		return 1;
	}
	printf("\nRandom numbers [0.0; 1.0]:\n");
	for (i = 0; i < 5; i++) {
		float r = (float)rand() / RAND_MAX;
		printf("%.6f\n", r);
	}
	printf("\nRandom numbers [0.0, %.2f]:\n", n);
	for (int i = 0; i < 5; i++) {
		float r = ((float)rand() / RAND_MAX) * n;
		printf("%.6f\n", r);
	}
	return 0;
}
