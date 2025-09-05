#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit lim;

    // 1. Maximum stack size (soft limit)
    if (getrlimit(RLIMIT_STACK, &lim) == 0) {
        printf("stack size: %ld\n", lim.rlim_cur);
    } else {
        perror("getrlimit(RLIMIT_STACK)");
    }

    // 2. Maximum number of processes (soft limit)
    if (getrlimit(RLIMIT_NPROC, &lim) == 0) {
        printf("process limit: %ld\n", lim.rlim_cur);
    } else {
        perror("getrlimit(RLIMIT_NPROC)");
    }

    // 3. Maximum number of file descriptors (soft limit)
    if (getrlimit(RLIMIT_NOFILE, &lim) == 0) {
        printf("max file descriptors: %ld\n", lim.rlim_cur);
    } else {
        perror("getrlimit(RLIMIT_NOFILE)");
    }

    return 0;
}

