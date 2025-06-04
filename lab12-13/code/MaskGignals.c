#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
	printf("Caught SIGINT\n");
}

int main() {
	signal(SIGINT, handle_sigint);

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigprocmask(SIG_BLOCK, &set, NULL); // blocking SIGINT

	while(1) {
		sleep(1);
	}

	return 0;
}
