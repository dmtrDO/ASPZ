#include <stdio.h>

void recursive_func(int depth) {
    printf("Recursion depth: %d\n", depth);
    depth++;
    recursive_func(depth);
}

int main() {
    recursive_func(1);
    return 0;
}