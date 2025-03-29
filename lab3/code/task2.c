#include <stdio.h>
#include <math.h>

int main(void) {
    double x = 0;
    for (long long i = 0; i < 1e12; i++) {
        x += sqrt(i);
    }
    return 0;
}