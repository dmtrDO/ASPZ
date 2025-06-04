#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	struct sigaction sa;
	sa.sa_handler = SIG_IGN;
	sa.sa_flags = SA_NOCLDWAIT;
	sigaction(SIGCHLD, &sa, NULL);

	if (fork() == 0) {
		printf("Child: PID = %d\n", getpid());
		_exit(0);
	}

	sleep(2);
	printf("Parent end\n");

	return 0;
}
