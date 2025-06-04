#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <setjmp.h>

sigjmp_buf env;

void handler(int sig) {
	printf("Got SIGSEGV, recovering...\n");
	siglongjmp(env, 1);
}

void* thread_func(void* arg) {
	if (sigsetjmp(env, 1) == 0) {
		printf("Thread: start\n");
		int*p = NULL;
		*p = 1; // calling SIGSEGV
	} else {
		printf("Thread: continue after crash\n");
	}
	return NULL;
}

int main() {
	signal(SIGSEGV, handler);
	pthread_t t;
	pthread_create(&t, NULL, thread_func, NULL);
	pthread_join(t, NULL);
	return 0;
}
