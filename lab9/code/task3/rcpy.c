
#include <stdio.h>
#include <stdlib.h>

int main() {
	system("touch data.txt");
	system("sudo cp data.txt /home/dima/copy_data.txt");
	FILE* f = fopen("/home/dima/copy_data.txt", "w");
	if (f == NULL) {
		fprintf(stderr, 
			"ERROR: can't fopen('/home/dima/copy_data.txt') !\n");
	} else {
		fprintf(f, "Hello world !");
		fclose(f);
	}
	system("rm /home/dima/copy_data.txt");
	return 0;
}



