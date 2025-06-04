#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig, siginfo_t* info, void* ctx) {
	printf("Received data: %d\n", info->si_value.sival_int);
}

int main() {
	struct sigaction sa = {0};
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGRTMIN, &sa, NULL);

	union sigval val;
	val.sival_int = 123;
	sigqueue(getpid(), SIGRTMIN, val);

	while (1);

	return 0;
}
