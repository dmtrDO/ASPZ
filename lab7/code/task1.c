#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* fp = popen("rwho", "r");
	if (fp == NULL) {
		printf("rwho popen failed\n");
		return 1;
	}
	char buffer[100];
	FILE* fp_more = popen("more", "w");
	if (fp_more == NULL) {
		printf("more popen failed\n");
		return 1;
	}
	while (fgets(buffer, sizeof(buffer), fp) != NULL) {
		fprintf(fp_more, "%s", buffer);
	}
	pclose(fp);
	pclose(fp_more);
	return 0;
}
