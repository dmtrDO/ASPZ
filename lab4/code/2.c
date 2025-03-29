#include <stdio.h>
#include <stdlib.h>

int main() {
    int xa = 1000000;
    int xb = 1000000;
    int num = xa * xb;
    char* ptr = malloc(num);
    if (ptr != NULL) {
        printf("Memory successfully allocated !\n at %p", ptr);
        free(ptr);
    } else {
        printf("Cannot allocate memory with size of %d bytes\n", num);
    }
    return 0;
}