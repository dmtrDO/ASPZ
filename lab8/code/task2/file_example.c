
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd = open("sequence.txt", O_RDONLY);
	if (fd == 1) {
		fprintf(stderr, "ERROR: can't reach open() !\n");
		return 1;
	}
	char buff[5];
	lseek(fd, 3, SEEK_SET);
	read(fd, buff, 4);
	buff[4] = '\0';
	printf("%s\n", buff);
}



