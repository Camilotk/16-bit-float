#include <stdio.h>
#include <stdlib.h>

#include "src/problem.h"

int main (void)
{
    printf("Hello, World!\n");
    printf("result if %d is multiple of %d: %s\n", 8, 3, isMultipleOf(8,2) ? "true" : "false");
    return EXIT_SUCCESS;
}
