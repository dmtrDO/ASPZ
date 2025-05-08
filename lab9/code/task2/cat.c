
#include <stdio.h>
#include <stdlib.h>

int main() {
	int status = system("sudo cat /etc/shadow");
	if (status == -1) {
		fprintf(stderr, "ERROR: can't reach system(...) !\n");
		return 1;
	}
	return 0;
}



