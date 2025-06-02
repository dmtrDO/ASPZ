#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define MAX 1024
int main() {
	char line[MAX];
	while (1) {
		printf("dumbsh > ");
		if (!fgets(line, MAX, stdin)) break;
		line[strcspn(line, "\n")] = 0;
		if (strcmp(line, "exit") == 0) break;
		pid_t pid = fork();
		if (pid == 0) {
			execlp(line, line, NULL);
			perror("exec failed");
			exit(1);
		} else {
			int status;
			pid_t pid = wait(&status);
			if (WIFEXITED(status)) {
				printf("Exited with code %d\n",
							WEXITSTATUS(status));
			}
		}
	}
	return 0;
}
