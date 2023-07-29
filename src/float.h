#ifndef FLOAT_H
#define FLOAT_H

// Define the amount of bits reserved for exponent and mantissa
#define EXP_BITS 5
#define MANTISSA_BITS 10
// Bits in unsigned
#define NON_SIGN_BITS (EXP_BITS + MANTISSA_BITS)

// Function declarations
unsigned int encode(double value);
char* encodeToBits(double value);
char* inspect(double value);
float decode(unsigned int value);

#endif
