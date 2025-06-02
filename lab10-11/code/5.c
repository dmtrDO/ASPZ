#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
	pid_t pid = fork();
	if (pid < 0) {
		perror("fork failed");
		return 1;
	}
	if (pid == 0) {
		printf("Child: exited with code 7\n");
		exit(7);
	} else {
		int status;
		wait(&status);
		if (WIFEXITED(status)) {
			int exit_code = WEXITSTATUS(status);
			printf("Parent: child process exited with code %d\n",
					exit_code);
		} else {
			printf("Parent: child process exited incorrectly\n");

		}
	}
	return 0;
}
