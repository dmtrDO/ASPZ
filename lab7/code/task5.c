
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PATH_MAX_SIZE 1024

#define TAB printf("    ")
#define FORK printf("\u251C\u2500\u2500 ")

void tree(char*);
void handle_closedir(DIR*);
DIR* handle_opendir(const char*);
void print_dir(const char*, int);
void print_reg(const char*, int);
char* quit_dir(char*);
void print_root_dir(const char*, int*);

int main () {
	char path[PATH_MAX_SIZE];
	if (getcwd(path, sizeof(path)) != NULL) {
		tree(path);
	} else {
	       	fprintf(stderr, "ERROR: can't reach getcwd()\n");
	}
	return 0;
}

void tree(char* path) {
	static int depth = -1;
	print_root_dir(path, &depth);
	DIR* dir = handle_opendir(path);
	struct dirent* entry;
	while ((entry = readdir(dir)) != NULL) {
		if (strcmp(entry->d_name, "..") == 0 
		 || strcmp(entry->d_name, ".") == 0) {
			continue;
		} else if (entry->d_type == DT_REG) {
			print_reg(entry->d_name, depth);
		} else if (entry->d_type == DT_DIR) {
			depth++;
			path = strcat(strcat(path, "/"), entry->d_name);
			DIR* subdir;
			while ((subdir = opendir(path)) == NULL && depth >= 0) {
				depth--;
				path = strcat(quit_dir(path), entry->d_name);
			} 
			handle_closedir(subdir);
			print_dir(path, depth);
			tree(path);
		} 
	}
	handle_closedir(dir);
}

void print_root_dir(const char* path, int* depth) {
	if (*depth == -1) {
		(*depth)++;
		print_dir(path, *depth);
	}
}

void print_reg(const char* file_name, int depth) {
	for (int i = 0; i <= depth; i++) {
		if (i == depth) {
			FORK;
			break;
		}
		TAB;
	}
	printf("%s\n", file_name);
	
}

void print_dir(const char* path, int depth) {
	for (int i = 0; i <  depth; i++) {
		if (i == depth - 1) {
			FORK;
			break;
		}
		TAB;
	}
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
	printf("%s\n", short_path);
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


