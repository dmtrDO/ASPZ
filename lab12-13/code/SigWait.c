#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
	printf("My PID is %d\n", getpid());

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigprocmask(SIG_BLOCK, &set, NULL);

	siginfo_t info;
	sigwaitinfo(&set, &info);

	printf("Got signal %d from PID %d\n", info.si_signo, info.si_pid);

	return 0;
}
