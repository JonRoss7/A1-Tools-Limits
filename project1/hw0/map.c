/* map.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* A statically allocated variable (bss) */
int foo;

/* A statically allocated, pre-initialized variable (data) */
volatile int stuff = 7;

/* forward */
int recur(int i);

void map_init(void) {
    /* stack variable */
    volatile int i = 0;

    /* dynamically allocate 2 chunks */
    volatile char *buf1 = malloc(100);
    volatile char *buf2 = malloc(100);

    printf("_main stack: = %p\n", (void*)&i);
    printf("static data: = %p\n", (void*)&stuff);
    printf("Heap: malloc 1: = %p\n", (void*)buf1);
    printf("Heap: malloc 2 = %p\n", (void*)buf2);

    recur(3);

    free((void*)buf1);
    free((void*)buf2);
}

int recur(int i) {
    volatile int local = 0;
    printf("recur call %d: stack@ %p\n", i, (void*)&local);
    if (i <= 0) return 0;
    return recur(i-1) + 1;
}

int main(int argc, char *argv[]) {
    /* print function addresses and some addresses of interest */
    printf("_main @ %p\n", (void*) &main);
    printf("recur @ %p\n", (void*) &recur);

    /* call init that does mallocs and recursion */
    map_init();

    return 0;
}

