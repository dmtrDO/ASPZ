#include <stdio.h>
#include <stdlib.h>

int main() {
    char* ptr = malloc(0);
    if (ptr != NULL) {
        printf("Memory successfully allocated at %p\n", ptr);
        free(ptr);
    } else {
        printf("Cannot allocate memory with size of 0 bytes\n");
    }
    return 0;
}