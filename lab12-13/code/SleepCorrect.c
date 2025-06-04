#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

void handle_sigint(int sig) {
	printf("Caught SIGINT (Ctrl + C), sleep interrupted\n");
}

int main() {
	signal(SIGINT, handle_sigint);

	struct timespec req = {1, 0}; // 1 sec
	while (nanosleep(&req, &req) == -1 && errno == EINTR) {
		printf("Sleep was interrupted, remaining: %ld nsec\n", 
							req.tv_nsec);
	}

	printf("Sleep completed !\n");


	return 0;
}
