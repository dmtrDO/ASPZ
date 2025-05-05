#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	char path[256], cmd[300], ans[4];
	FILE* f = popen("find . -type f -name \"*.c\" -user \"$(whoami)\"","r");
	if (f == NULL) {
		fprintf(stderr, "ERROR: can't popen !\n");
		return 1;
	}
	while (fgets(path, sizeof(path), f)) {
		path[strcspn(path, "\n")] = 0;
		printf("%s - give reading permission for others (y/n) ? ",path);
		fgets(ans, sizeof(ans), stdin);
		if (ans[0] == 'y' || ans[0] == 'Y') {
			snprintf(cmd, sizeof(cmd), "chmod a+r \"%s\"", path);
			system(cmd);
		} else if (ans[0] == 'n' || ans[0] == 'N') {
			snprintf(cmd, sizeof(cmd), "chmod a-r \"%s\"", path);
			system(cmd);
		} 
	}
	pclose(f);
	return 0;
}
