#include <stdio.h>
#include <string.h>
#define LINE_MAX_SIZE 50
int main(int argc, char** argv) {
	if (argc < 3) {
		perror("You missed arguments\n");
		return 1;
	}
	FILE* f = fopen(argv[1], "r");
	if (f == NULL) {
		perror("fopen failed\n");
		return 1;
	}
	char line[LINE_MAX_SIZE];
	while (fgets(line, sizeof(line), f)) {
		if (strstr(line, argv[2]))
			printf("%s\n", line);
	}
	fclose(f);
	return 0;
}
