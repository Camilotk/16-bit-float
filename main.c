#include <stdio.h>
#include <stdlib.h>

#include "src/float.h"

int main(void) {
    double value = 12.52571;
    printf("Hello, World!\n");

    printf("Encoded value: %u\n", encode(value));
    printf("Encoded value in bits: %s\n", encodeToBits(value));

    char* inspection = inspect(value);
    printf("%s\n", inspection);

    printf("Decoded value: %f\n", decode(encode(value)));

    // Free the dynamically allocated memory for the inspection string
    free(inspection);

    return EXIT_SUCCESS;
}
