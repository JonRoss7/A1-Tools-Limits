#include <stdio.h>
#include <stdlib.h>

/* A statically allocated variable */
int foo;

/* Function prototype, implemented elsewhere */
extern int recur(int i);

/* A statically allocated, pre-initialized variable */
volatile int stuff = 7;

/* Example helper function from map.c (originally in main) */
void map_init(void) {
    /* Stack allocated variable */
    volatile int i = 0;

    /* Dynamically allocate some memory */
    volatile char *buf1 = malloc(100);
    volatile char *buf2 = malloc(100);

    /* Call recur as in original main */
    recur(3);

    /* Clean up */
    free((void*)buf1);
    free((void*)buf2);
}

