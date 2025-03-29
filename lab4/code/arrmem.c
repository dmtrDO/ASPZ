#include <stdio.h>
#include <stdlib.h>

struct sbar {
    char a;
    int b;
    float c;
};

int main() {
    struct sbar* ptr, *newptr;
    ptr = calloc(1000, sizeof(struct sbar));
    //newptr = realloc(ptr, 500 * sizeof(struct sbar));
    newptr = reallocarray(ptr, 500, sizeof(struct sbar));
    return 0;
}