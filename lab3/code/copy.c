#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FILE_SIZE 10

void copy_file(const char* src, const char* dest) {
    char buffer[MAX_FILE_SIZE + 1];

    FILE* source = fopen(src, "rb");
    if (source == NULL) {
        printf("Cannot open file %s for reading\n", src);
        exit(1);
    }

    FILE* destination = fopen(dest, "wb");
    if (destination == NULL) {
        printf("Cannot open file %s for writing\n", dest);
        fclose(source);
        exit(1);
    }

    fseek(source, 0, SEEK_END);
    long file_size = ftell(source);
    fseek(source, 0, SEEK_SET);

    if (file_size > MAX_FILE_SIZE) {
        printf("File size exceeds the maximum allowed limit\n");
        fclose(source);
        fclose(destination);
        exit(1);
    }

    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes_read, destination);
    }

    fclose(source);
    fclose(destination);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Program need two arguments\n");
        return 1;
    }
    copy_file(argv[1], argv[2]);
    return 0;
}