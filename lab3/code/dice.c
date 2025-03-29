#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

#define MAX_SIZE 10 * 1024
#define FILE_NAME "dice_rolls.txt"

int file_size() {
    struct stat st;
    return (stat(FILE_NAME, &st) == 0) ? st.st_size : 0;
}

int main() {
    FILE* f = fopen(FILE_NAME, "a");
    if (!f) return 1;

    srand(time(NULL));
    while (file_size() < MAX_SIZE) {
        fprintf(f, "%d\n", (rand() % 6) + 1);
        fflush(f);
    }
    fclose(f);
    return 0;
}