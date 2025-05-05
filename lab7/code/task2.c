#include <stdio.h>
#include <dirent.h>

int main() {
	DIR* directory;
	struct dirent* entry;

	directory = opendir(".");
	if (directory == NULL) {
		printf("Error opening directory\n");
		return 1;
	}

	while ((entry = readdir(directory)) != NULL) {
		printf("File name: %s, file type: %d\n", entry->d_name,  entry->d_type);
	}
	if (closedir(directory) == -1) {
		perror("Error closing directory\n");
		return 1;
	}

	return 0;
}
