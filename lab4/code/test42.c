#include <stdio.h>
#include <stdlib.h>

int main() {
    char* ptr = malloc(1);
    if (ptr == NULL) {
        printf("It's not OK\n");
        free(ptr);
        exit(1);
    }
    free(ptr);
    printf("after free() ptr = %p\n", ptr);
    return 0;
}