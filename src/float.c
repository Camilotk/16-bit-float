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
