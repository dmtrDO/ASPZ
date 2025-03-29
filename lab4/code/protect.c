#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char **argv) {
    long pgsz = sysconf(_SC_PAGESIZE);
    size_t len = 3*pgsz;
    void* ptr;
    posix_memalign(&ptr, pgsz, len);
    if (!ptr) {
        fprintf(stderr, "posix_memalign() failed\n");
        return 1;
    }
    if (mprotect(ptr, len, PROT_READ) == -1) {
        perror("mprotect failed\n");
        free(ptr);
        return 1;
    }
    ((char*)ptr)[0] = 'a';
    free(ptr);
    return 0;
}