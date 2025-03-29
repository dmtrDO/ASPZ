#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#define TIME_LIMIT 5

void timeout_handler(int signum) {
    printf("Time out !\n");
    exit(1);
}

int main(void) {
    signal(SIGALRM, timeout_handler);
    alarm(TIME_LIMIT);

    srand(time(NULL));
    int numbers_49[7], numbers_36[6];

    for (int i = 0; i < 7; i++) numbers_49[i] = rand() % 49 + 1;
    for (int i = 0; i < 6; i++) numbers_36[i] = rand() % 36 + 1;

    printf("Numbers with 1-49: ");
    for (int i = 0; i < 7; i++) printf("%d ", numbers_49[i]);

    int i = 0;
    while (1) {
    	sleep(1);
	printf("\nWaiting for signal: %ds\n", i);
	i++;
    }

    printf("\nNumbers with 1-36: ");
    for (int i = 0; i < 6; i++) printf("%d ", numbers_36[i]);
    printf("\n");

    return 0;
}