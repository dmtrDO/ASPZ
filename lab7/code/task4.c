#include <stdio.h>
#define MAX_LINE_SIZE 50
#define MAX_LINES_TO_SEE 20
int main(int argc, char** argv) {
	if (argc < 2) {
		fprintf(stderr, "Error: missed argument/s !\n");
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		FILE* fp = fopen(argv[i], "r");
		if (fp == NULL) {
			fprintf(stderr, "Error: can't open the file !\n");
			return 1;
		}
		printf("\n--- File: %s ---\n\n", argv[i]);
		char line[MAX_LINE_SIZE];
		int counter = 0;
		while (fgets(line, sizeof(line), fp)) {
			printf("%s", line);
			counter++;
			if (counter == MAX_LINES_TO_SEE) {
				printf("\n--- Press enter to continue ---");
				while (getchar() != '\n') {}
				for (int i = 0; i < 2; i++) 
					printf("\033[1A\033[K\r");
				counter = 0;
			}
		}
		fclose(fp);
	}
	return 0;
}
