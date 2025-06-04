#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
	printf("Signal %d is got\n", sig);
}

int main() {
	struct sigaction sa;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;

	sigaction(SIGINT, &sa, NULL);

	printf("Waiting for input (enter Ctrl + C)...\n");
	char buff[100];
	read(STDIN_FILENO, buff, sizeof(buff));

	printf("Entered: %s\n", buff);
	return 0;
}
