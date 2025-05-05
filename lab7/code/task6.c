
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PATH_MAX_SIZE 1024
#define MAX_DIRS 1000

char dirs[PATH_MAX_SIZE][MAX_DIRS];
int num_of_dirs = 0;

void tree(char*);
void handle_closedir(DIR*);
DIR* handle_opendir(const char*);
void add_dir(const char*, int);
char* quit_dir(char*);

void swap(char* a, char* b) {
	char temp[PATH_MAX_SIZE];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

int main () {
	char path[PATH_MAX_SIZE];
	if (getcwd(path, sizeof(path)) != NULL) {
		tree(path);
	} else {
	       	fprintf(stderr, "ERROR: can't reach getcwd()\n");
	}
	for (int i = 0; i < num_of_dirs; i++) {
		for (int j = 0; j < num_of_dirs - i - 1; j++) {
			if (strcmp(dirs[j], dirs[j + 1]) > 0) {
				swap(dirs[j], dirs[j + 1]);
			}
		}
	}
	for (int i = 0; i < num_of_dirs; i++) {
		printf("%s\n", dirs[i]);
	}
	return 0;
}

void tree(char* path) {
	static int depth = -1;
	DIR* dir = handle_opendir(path);
	struct dirent* entry;
	while ((entry = readdir(dir)) != NULL) {
		if (strcmp(entry->d_name, "..") == 0 
		 || strcmp(entry->d_name, ".") == 0) {
			continue;
		} else if (entry->d_type == DT_DIR) {
			depth++;
			path = strcat(strcat(path, "/"), entry->d_name);
			DIR* subdir;
			while ((subdir = opendir(path)) == NULL && depth >= 0) {
				depth--;
				path = strcat(quit_dir(path), entry->d_name);
			}
			handle_closedir(subdir);
			add_dir(path, depth);
			tree(path);
		} 
	}
	handle_closedir(dir);
}

void add_dir(const char* path, int depth) {
	char short_path[PATH_MAX_SIZE];
	int index = 0;
	for (int i = strlen(path) - 1; i >= 0; i--, index++) {
		if (path[i] == '/') {
			short_path[index] = '\0';
			break;
		}
		short_path[index] = path[i];
	}
	
	int short_len = strlen(short_path);
	for (int i = 0; i < short_len / 2; i++) {
		char temp = short_path[i];
		short_path[i] = short_path[short_len - 1 - i];
		short_path[short_len - 1 - i] = temp;
	}
	for (int i = 0; i < short_len; i++) {
		dirs[num_of_dirs][i] = short_path[i];
	}
	dirs[num_of_dirs][short_len] = '\0';
	num_of_dirs++;
}

char* quit_dir(char* path) {
	int deleted = 0;
	for (int i = strlen(path) - 1; i >= 0; i--) {
		if (path[i] == '/') {
			path[i] = '\0';
			deleted++;
		}
		if (deleted == 2) {
			break;
		}
	}
	return strcat(path, "/");
}

void handle_closedir(DIR* dir) {
	if (closedir(dir) == -1) {
		fprintf(stderr, "ERROR: can't close directory !\n");
		exit(1);
	}
}

DIR* handle_opendir(const char* path) {
	DIR* dir = opendir(path);
	if (dir == NULL) {
		exit(1);
		fprintf(stderr, "ERROR: can't open directory !\n");
	}
	return dir;
}


