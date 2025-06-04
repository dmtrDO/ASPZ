#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/signalfd.h>

int main() {
	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	sigprocmask(SIG_BLOCK, &mask, NULL);

	int sfd = signalfd(-1, &mask, 0);
	struct signalfd_siginfo fdsi;

	printf("PID: %d\n", getpid());
	read(sfd, &fdsi, sizeof(fdsi));
	printf("Got signal: %d\n", fdsi.ssi_signo);

	return 0;
}
