# IEEE 754 Float Implementation

This project provides a basic implementation of IEEE 754-2019 floating-point representation for 16-bit floats. The implementation includes functions to encode and decode floating-point values, inspect the internal binary representation, and a simple REPL (Read-Eval-Print Loop) to interact with the functionalities.

## Introduction

The IEEE 754 standard defines the format for representing floating-point numbers in computers. This project provides a simplified implementation for 16-bit floats using 1 bit for the sign, 5 bits for the power value (exponent), and 10 bits for the mantissa (fractional part). Although this implementation does not cover all rounding strategies, it serves as an educational example of how floating-point numbers work in memory.

## How this works

The implementation follows the IEEE 754 standard for encoding and decoding double-precision floating-point numbers. A 16-bit representation is used, with 1 bit for the sign, 5 bits for the exponent, and 10 bits for the mantissa.

### Encoding:

To encode a double-precision floating-point number, the following steps are performed:

1. Determine the sign (negative or positive) of the number.

2. Check if the value is exactly zero. If so, return a special representation with all bits set to 0, except for the sign bit.

3. Calculate the exponent by finding the power of 2 that the number falls between and adjust it to be biased by 15. The exponent range is from 1 to 30, with 0 and 31 reserved for special cases.

4. Calculate the percentage between the two bounds of the exponent and convert it to a 10-bit mantissa value. The formula used to calculate the percentage is:

   $$ percentage = \frac{{\text{{value}} - \text{{lower bound}}}}{{\text{{upper bound}} - \text{{lower bound}}}} $$

Where "value" is the input number, "lower bound" is the value of $\(2^{\text{exponent} - 15}\)$, and "upper bound" is the value of $\(2^{\text{exponent} - 15 + 1}\)$.

5. Combine the sign, exponent, and mantissa to form the 16-bit unsigned integer representation.

The formula for encoding can be represented as:

$$ N = (-1)^{\text{sign}} \times (1 + \text{percentage}) \times 2^{\text{exponent} - 15} $$

### Decoding:

To decode a 16-bit unsigned integer representation back to its equivalent double-precision floating-point value, the following steps are performed:

1. Extract the sign bit, exponent bits, and mantissa bits from the 16-bit integer.

2. Handle special cases for zero, infinity, and NaN.

3. Calculate the whole part and percentage of the number from the exponent and mantissa values. The formula used to calculate the percentage is the same as for encoding.

4. Combine the sign, whole part, and percentage to obtain the final decoded floating-point value.

The formula for decoding can be represented as the same used in encoding.

### Range:

The implementation supports a wide range of double-precision floating-point values. The exponent range is from 0 to 31, which allows for a wide range of magnitudes. The mantissa uses 10 bits, which provides a high level of precision for the fractional part of the number.

| Exponent (n) | Numerical Range                                     |
|--------------|----------------------------------------------------|
| 0            | \[0.0000000000000000, 0.0000000000000000\]          |
| 1            | \[0.0000610351562500, 0.0001220703125000\]          |
| 2            | \[0.0001220703125000, 0.0002441406250000\]          |
| 3            | \[0.0002441406250000, 0.0004882812500000\]          |
| 4            | \[0.0004882812500000, 0.0009765625000000\]          |
| 5            | \[0.0009765625000000, 0.0019531250000000\]          |
| 6            | \[0.0019531250000000, 0.0039062500000000\]          |
| 7            | \[0.0039062500000000, 0.0078125000000000\]          |
| 8            | \[0.0078125000000000, 0.0156250000000000\]          |
| 9            | \[0.0156250000000000, 0.0312500000000000\]          |
| 10           | \[0.0312500000000000, 0.0625000000000000\]          |
| 11           | \[0.0625000000000000, 0.1250000000000000\]          |
| 12           | \[0.1250000000000000, 0.2500000000000000\]          |
| 13           | \[0.2500000000000000, 0.5000000000000000\]          |
| 14           | \[0.5000000000000000, 1.0000000000000000\]          |
| 15           | \[1.0000000000000000, 2.0000000000000000\]          |
| 16           | \[2.0000000000000000, 4.0000000000000000\]          |
| 17           | \[4.0000000000000000, 8.0000000000000000\]          |
| 18           | \[8.0000000000000000, 16.0000000000000000\]         |
| 19           | \[16.0000000000000000, 32.0000000000000000\]        |
| 20           | \[32.0000000000000000, 64.0000000000000000\]        |
| 21           | \[64.0000000000000000, 128.0000000000000000\]       |
| 22           | \[128.0000000000000000, 256.0000000000000000\]      |
| 23           | \[256.0000000000000000, 512.0000000000000000\]      |
| 24           | \[512.0000000000000000, 1024.0000000000000000\]     |
| 25           | \[1024.0000000000000000, 2048.0000000000000000\]    |
| 26           | \[2048.0000000000000000, 4096.0000000000000000\]    |
| 27           | \[4096.0000000000000000, 8192.0000000000000000\]    |
| 28           | \[8192.0000000000000000, 16384.0000000000000000\]   |
| 29           | \[16384.0000000000000000, 32768.0000000000000000\]  |
| 30           | \[32768.0000000000000000, 65536.0000000000000000\]  |
| 31           | \[65536.0000000000000000, 131072.0000000000000000\] |

### Rounding:

It's important to note that this implementation uses a simple rounding strategy for the encoding process. This may not fully comply with all edge cases specified in the IEEE 754 standard. For applications that require rigorous compliance with the standard, additional logic and rounding strategies would be needed.

## Functions

The implementation includes the following main functions:

---

### `unsigned int encode(double value)`

Encodes a double-precision floating-point number into a 16-bit unsigned integer representation.

**Parameters:**
- `value`: The double-precision floating-point number to be encoded.

**Returns:**
The encoded 16-bit unsigned integer.

---

### `char* encodeToBits(double value)`

Encodes a double-precision floating-point number into a binary string representation.

**Parameters:**
- `value`: The double-precision floating-point number to be encoded.

**Returns:**
A dynamically allocated binary string representation of the encoded value. Remember to free the allocated memory after use.

---

### `char* inspect(double value)`

Provides an inspection of the internal binary representation of a double-precision floating-point number.

**Parameters:**
- `value`: The double-precision floating-point number to be inspected.

**Returns:**
A dynamically allocated inspection string containing details about the binary representation. Remember to free the allocated memory after use.

---

### `float decode(unsigned int value)`

Decodes a 16-bit unsigned integer representation into its equivalent double-precision floating-point value.

**Parameters:**
- `value`: The 16-bit unsigned integer to be decoded.

**Returns:**
The decoded double-precision floating-point value.

---

### TL;DR.
- `unsigned int encode(double value)`: Encodes a double-precision floating-point number into a 16-bit unsigned integer representation.
- `char* encodeToBits(double value)`: Encodes a double-precision floating-point number into a binary string representation.
- `char* inspect(double value)`: Provides an inspection of the internal binary representation of a double-precision floating-point number.
- `float decode(unsigned int value)`: Decodes a 16-bit unsigned integer representation into its equivalent double-precision floating-point value.

```c
unsigned int encode(double value);
char* encodeToBits(double value);
char* inspect(double value);
float decode(unsigned int value);
```

## Usage

### Importing the Header

To use the IEEE 754 float implementation in your own projects, follow these steps:

1. Copy the `float.h` header file from the `src` directory into your project's include directory.
2. Include the `float.h` header in your source files where you want to use the IEEE 754 functions.

Example:
```c
#include "path/to/float.h"

int main() {
    double value = 12.345;
    unsigned int encoded = encode(value);
    // Rest of the code
    return 0;
}
```

### Using the REPL

The project includes a REPL (Read-Eval-Print Loop) that allows interactive use of the IEEE 754 functions. The REPL supports the following commands:

- `e <float number>`: Encodes the provided floating-point number and prints the encoded value.
- `d <unsigned int>`: Decodes the provided 16-bit unsigned integer and prints the decoded value.
- `i <float number>`: Inspects the provided floating-point number and prints the internal binary representation.
- `q`: Exits the REPL.

To use the REPL, simply run the main program and enter the desired commands.

## Running the Program

### Main Program

To run the main program:

1. Compile the program using the provided Makefile:
```
$ make run
```
2. The program will start with:
```
Enter a command (e <float> / d <unsigned int> / i <float> / q):
```

### Unit Tests

To run the unit tests:

```
$ make test
```

This command will compile the tests and execute them, providing information about the test results.
