#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 10;
    int b = a++ + ++a;
    printf("%d\n", b);
    return 0;
}