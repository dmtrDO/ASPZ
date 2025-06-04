#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <ucontext.h>

void handler(int sig, siginfo_t* info, void* context) {
	ucontext_t* uc = (ucontext_t*)context;
#if defined(__x86_64__)
	printf("RIP:%llx\n",(unsigned long long)uc->uc_mcontext.mc_rip);
#endif
	exit(1);
}

int main() {
	struct sigaction sa = {0};
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGSEGV, &sa, NULL);
	int* p = NULL;
	*p = 42; // calling SIGSEGV
	
	return 0;
}
