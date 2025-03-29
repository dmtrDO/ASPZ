#include <stdio.h>
#include <stdlib.h>

int main() {
    char* ptr = malloc(10);
    if (ptr == NULL) {
        printf("Cannot allocate memory\n");
        exit(1);
    }

    char* new_ptr = realloc(ptr, 0);
    if (new_ptr == NULL) {
        printf("Cannot reallocate memory\n");
        free(ptr);
        exit(1);
    }

    free(new_ptr);
    printf("All the allocations are successful !\n");
    return 0;
}