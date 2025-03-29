#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long long value_to_alloc = 10;
    while(1) {
        char* ptr = malloc(value_to_alloc);
        if (ptr != NULL) {
            printf("Memory allocation size in bytes is %lld at address %p\n", value_to_alloc, ptr);
            value_to_alloc *= 2;
            free(ptr);
        } else {
            free(ptr);
            printf("Cannot allocate memory with size %lld\n", value_to_alloc);
            exit(1);
        }
    }
    return 0;
}