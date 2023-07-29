#ifndef FLOAT_H
#define FLOAT_H

// Define the amount of bits reserved for exponent and mantissa
#define EXP_BITS 5
#define MANTISSA_BITS 10
// Bits in unsigned
#define NON_SIGN_BITS (EXP_BITS + MANTISSA_BITS)

// Function to encode a double value to 16-bit representation
unsigned int encode(double value);

// Function to encode a double value to its 16-bit binary representation
char* encodeToBits(double value);

// Function to inspect the 16-bit binary representation of a double value
char* inspect(double value);

// Function to decode a 16-bit representation back to a double value
double decode(unsigned int value);

#endif // FLOAT_H

