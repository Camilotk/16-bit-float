#include <stdbool.h>

// Define the amount of bits reserved for expoent and mantissa
#define EXP_BITS 5
#define MANTISSA_BITS 10
// Bits in unsigned
#define NON_SIGN_BITS (EXP_BITS + MANTISSA_BITS)

// definitions
unsigned int encode(double value);
char* encodeToBits(double value);
