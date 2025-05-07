
#include <stdio.h>
#include <unistd.h>

int main () {
	char msg[] = "Hello!";
	size_t nbytes = sizeof(msg);
	ssize_t count = write(-1, msg, nbytes);
	if (count == -1) {
		printf("Other returned value (%ld) than nbytes (%ld).\n",
			       count, nbytes);
	}	
	return 0;
}



