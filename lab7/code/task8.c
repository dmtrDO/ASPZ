
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define ANSWER 4

int main() {
	DIR* dir = opendir(".");
	struct dirent* entry;
	char ans[ANSWER];
	if (dir == NULL) {
		perror("ERROR: can't reach opendir !\n");
		return 1;
	}
	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_type == DT_REG) {
			printf("%s - delete (y/n) ? ", entry->d_name);
			fgets(ans, sizeof(ans), stdin);
			if (ans[0] == 'y' || ans[0] =='Y') {
				if (remove(entry->d_name) == 0) {
					printf("FIle %s deleted\n",
						       	entry->d_name);
				} else {
					perror("ERROR: can't remove file!\n");
				}
			}		
		}
	}
	if (closedir(dir) == -1) {
		perror("ERROR: can't close dir !\n");
		return 1;
	}
	return 0;
}
