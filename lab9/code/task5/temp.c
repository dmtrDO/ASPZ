
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	const char* file = "temp.txt";

	open("temp.txt", O_CREAT | O_WRONLY);

	system("sudo chown root temp.txt");
	system("sudo chmod 600 temp.txt");

	if (access(file, R_OK) == 0) puts("Reading enabled !\n");
	else puts("Reading disabled !\n");

	if (access(file, W_OK) == 0) puts("Writing enabled !\n");
	else puts("Writing disabled !\n");

	return 0;
}



