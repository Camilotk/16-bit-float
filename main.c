#include <stdio.h>
#include <stdlib.h>

#include "src/float.h"

int main(void) {
    double value = 12.52571;
    printf("Hello, World!\n");

    printf("%u\n", encode(value));
    printf("%s\n", encodeToBits(value));

    char* inspection = inspect(value);
    printf("%s\n", inspection);

    // Free the dynamically allocated memory for the inspection string
    free(inspection);

    return EXIT_SUCCESS;
}
