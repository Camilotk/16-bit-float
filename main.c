#include <stdio.h>
#include <stdlib.h>

#include "src/float.h"

int main (void)
{
    double value = 12.52571;
    printf("Hello, World!\n");

    printf("%u \n", encode(value));
    printf("%s \n", encodeToBits(value));
    return EXIT_SUCCESS;
}
