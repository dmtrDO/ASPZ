#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 1000

int main() {
	FILE* fp = fopen("/etc/passwd", "r");
	if (fp == NULL) {
		fprintf(stderr, "ERROR: cant oopen '/etc/passwd' !\n");
		exit(1);
	}
	int uid, currid = getuid();
	char line[LINE_SIZE], *token;
	while (fgets(line, sizeof(line), fp)) {
		token = strtok(line, ":");
		strtok(NULL, ":");
		uid = atoi(strtok(NULL, ":"));
		if (uid >= 1000 && uid != currid) {
			printf("%s\n", token);
		}
	}
	pclose(fp);
	return 0;
}
