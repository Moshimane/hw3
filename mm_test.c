/* A simple test harness for memory alloction. */

#include "mm_alloc.h"
#include <stdio.h>
#include <assert.h>

int stuff;

int main(int argc, char **argv)
{
    int *data;
  
    data = (int*) mm_malloc(4);
   
    printf("_main @ %lx\n", main);
    printf("_main stack %lx\n", &data);
    printf("static data: %lx\n", &stuff);
    printf("Heap: malloc: %lx\n", data);

    data[0] = 1;
    mm_free(data);
    printf("malloc sanity test successful!\n");

    data = (int*) mm_malloc(0);
    mm_free(data);
   printf("Zero test successful!\n");

    data = (int*) mm_malloc(-1);
    mm_free(data);
   printf("Negative test successful!\n");

    void* array[15];
    array[0] = (int*)mm_malloc(3);
    array[1] = (int*)mm_malloc(8);
    array[2] = (int*)mm_malloc(4);
    array[3] = (int*)mm_malloc(7);
    mm_free(array[1]);
    array[4] = (int*)mm_malloc(7);
    printf("array[1] %x, array[5] %x\n", array[1], array[4]);
    mm_free(array[0]);
    mm_free(array[3]);
    mm_free(array[2]);
    assert(array[1] == array[4]);
    mm_free(array[4]);
    array[3] = (int*)mm_malloc(6);
    fprintf(stderr, "array[0]: %x array[1]: %x\n", array[0], array[3]);
    assert(array[0] == array[3]);
    mm_free(array[3]);
    return 0;
}
