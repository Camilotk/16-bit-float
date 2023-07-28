#include <stdio.h>
#include <stdbool.h>
#include <math.h>

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
    static char binary[17]; // 16 bits + null terminator
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

