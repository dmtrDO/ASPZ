
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define FNAME "data.txt"
#define TMP_FNAME "tmp.txt"
#define SIZE 14
#define DATA "Hello world !"

void handle_fopen(const char* path);
void handle_fopen_error(FILE* fp);
void show_file(const char* path);
void vvrite(int fd, const char* buf, size_t nbytes);
void handle_file_descriptor(int fd);
void get_file_content(const char* path, char* buff);
int compare(const char* str1, const char* str2, size_t size);

int main() {
	handle_fopen(FNAME);
	char data[SIZE] = DATA;

	handle_fopen(TMP_FNAME);
	char tmp_data[SIZE];
	int tmp_fd = open(TMP_FNAME, O_CREAT | O_WRONLY);
	handle_file_descriptor(tmp_fd);
	
	vvrite(tmp_fd, data, SIZE);
	if (tmp_fd >= 0) {
		close(tmp_fd);
	}
	get_file_content(TMP_FNAME, tmp_data);
	if (compare(data, tmp_data, SIZE) == 0) {
		if (rename(TMP_FNAME, FNAME) != 0) {
			fprintf(stderr, "ERROR: can't rename files !\n");
		}
	}
	
	show_file(FNAME);
	
	return 0;
}

int compare(const char* str1, const char* str2, size_t size) {
	for (int i = 0; i < size; i++) {
		if (str1[i] != str2[i]) {
			return 1;
		}
	}
	return 0;
}

void get_file_content(const char* path, char* buff) {
	FILE* fp = fopen(path, "r");
	handle_fopen_error(fp);
	char ch;
	int i = 0;
	while ((ch = fgetc(fp)) != EOF) {
		buff[i] = ch;
		i++;
	}
}

void handle_file_descriptor(int fd) {
	if (fd == -1) {
		fprintf(stderr, "ERROR: can't open file !\n");
		exit(1);
	}
}

void vvrite(int fd, const char* buf, size_t nbytes) {
	for (int i = 0; i < nbytes; i++) {
		write(fd, &buf[i], 1);
		if (i == SIZE / 2) {
	//		break;
		}
	}
}

void handle_fopen (const char* path) {
	FILE* fp = fopen(path, "w");
	handle_fopen_error(fp);
	fclose(fp);
}

void handle_fopen_error(FILE* fp) {
	if (fp == NULL) {
		fprintf(stderr, "ERROR: can't open file !\n");
		exit(1);
	}
}

void show_file(const char* path) {
	FILE* fp = fopen(path, "r");
	handle_fopen_error(fp);
	char ch;
	printf("----- %s -----\n", path);
	while ((ch = fgetc(fp)) != EOF) {
		printf("%c", ch);
	}
	printf("\n");
	fclose(fp);
}

