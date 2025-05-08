
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_access_rwx(const char* path) {
	printf("\n------- %s ------ \n", path);
	char cmd[100];
	sprintf(cmd, "ls -l %s | head -5", path);
	system(cmd);
}

int main() {
	char path1[] = "/home";
	char path2[] = "/usr/bin";
	char path3[] = "/etc";
	char *path[] = { path1, path2, path3 };
	for (int i = 0; i < 3; i++) {
		check_access_rwx(path[i]);
	}
	return 0;	
}



