#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>  
#include <string.h>  

#include "float.h"

unsigned int encode(double value) {
    // Determine if the value is negative
    int isNegative = value < 0;

    // Check if the value is exactly zero
    if (value == 0) {
        // Return a special representation if it is.
        return isNegative ? (1 << NON_SIGN_BITS) : 0;
    }

    // Calculate the exponent
    int exponent = (int) floor(log(fabs(value)) / log(2));
    double lowerBound = pow(2, exponent);
    double upperBound = pow(2, exponent+1);
    exponent = (exponent + 15) & 0b11111;

    // Calculate porcentage between bounds
    double percentage = (fabs(value) - lowerBound) / (upperBound - lowerBound);
    unsigned int mantissa = (unsigned int) (1024 * percentage);

    // Combine sign, exponent and mantissa
    return (isNegative << NON_SIGN_BITS) | (exponent << MANTISSA_BITS) | mantissa;

    return 0;
}

// Function to convert an unsigned integer to its binary representation
char* intToBinary(unsigned int num) {
    char* binary = (char*)malloc(17); // Allocate memory for the binary string (16 bits + null terminator)
    if (binary == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 15; i >= 0; i--) {
        binary[15 - i] = ((num >> i) & 1) + '0'; // Extract each bit and convert to '0' or '1'
    }
    binary[16] = '\0'; // Null-terminate the string
    return binary;
}

// Function to encode a double-precision floating-point number and return the binary representation
char* encodeToBits(double value) {
    unsigned int encoded = encode(value);
    return intToBinary(encoded);
}

char* inspect(double value) {
    unsigned int encoded = encode(value);
    char* binaryString = intToBinary(encoded);

    // Allocate memory for the inspection string
    char* inspection = (char*)malloc(256); // Adjust the size accordingly if needed
    if (inspection == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Print the inspection details with colored output
    sprintf(inspection, "The %.5f value is encoded in the value %u that is represented in memory as \x1b[32m%s\x1b[0m.\n\n", value, encoded, binaryString);
    sprintf(inspection + strlen(inspection), "0                      = \x1b[34msign\x1b[0m, this is a %s number.\n", (encoded & (1 << NON_SIGN_BITS)) ? "negative" : "positive");
    sprintf(inspection + strlen(inspection), "1-5                    = \x1b[34mpower\x1b[0m, in this case is the value \x1b[34m<%.5d>\x1b[0m in decimal.\n", (encoded >> MANTISSA_BITS) & 0b11111);
    sprintf(inspection + strlen(inspection), "6-15                   = \x1b[34mmantissa\x1b[0m, in this case is the value \x1b[32m<%.5d>\x1b[0m in decimal.\n", encoded & 0b1111111111);

    // Free the dynamically allocated memory for the binary string
    free(binaryString);

    return inspection;
}

