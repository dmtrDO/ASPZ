#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig, siginfo_t* info, void* ucontext) {
	printf("ERROR: signal %d, address %p\n", sig, info->si_addr);
	_exit(1);
}

int main() {
	struct sigaction sa = {0};
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGSEGV, &sa, NULL);

	int* p = NULL;
	*p = 1;

	return 0;
}
