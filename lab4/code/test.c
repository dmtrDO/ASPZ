#include <stdio.h>
#include <stdlib.h>

int main() {
    char* ptr = malloc(-5);
    if (ptr != NULL) {
        printf("Successful allocation at %p\n", ptr);
        free(ptr);
    } else {
        printf("Cannot allocate negative memory\n");
    }
    return 0;
}