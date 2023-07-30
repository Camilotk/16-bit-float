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

The formula for decoding can be represented as:

$$ value = (-1)^{\text{sign}} \times (1 + \text{percentage}) \times 2^{\text{exponent} - 15} $$

### Range:

The implementation supports a wide range of double-precision floating-point values. The exponent range is from 1 to 30, which allows for a wide range of magnitudes. The mantissa uses 10 bits, which provides a high level of precision for the fractional part of the number.

| Exponent (2 ^ n\] | Numerical Range       |
|------------------|-----------------------|
|        1         | \[-0.0009765625, 0.0009765625\]  |
|        2         | \[-0.001953125, 0.001953125\]    |
|        3         | \[-0.00390625, 0.00390625\]      |
|        4         | \[-0.0078125, 0.0078125\]        |
|        5         | \[-0.015625, 0.015625\]          |
|        6         | \[-0.03125, 0.03125\]            |
|        7         | \[-0.0625, 0.0625\]              |
|        8         | \[-0.125, 0.125\]                |
|        9         | \[-0.25, 0.25\]                  |
|        10        | \[-0.5, 0.5\]                    |
|        11        | \[-1.0, 1.0\]                    |
|        12        | \[-2.0, 2.0\]                    |
|        13        | \[-4.0, 4.0\]                    |
|        14        | \[-8.0, 8.0\]                    |
|        15        | \[-16.0, 16.0\]                  |
|        16        | \[-32.0, 32.0\]                  |
|        17        | \[-64.0, 64.0\]                  |
|        18        | \[-128.0, 128.0\]                |
|        19        | \[-256.0, 256.0\]                |
|        20        | \[-512.0, 512.0\]                |
|        21        | \[-1024.0, 1024.0\]              |
|        22        | \[-2048.0, 2048.0\]              |
|        23        | \[-4096.0, 4096.0\]              |
|        24        | \[-8192.0, 8192.0\]              |
|        25        | \[-16384.0, 16384.0\]            |
|        26        | \[-32768.0, 32768.0\]            |
|        27        | \[-65536.0, 65536.0\]            |
|        28        | \[-131072.0, 131072.0\]          |
|        29        | \[-262144.0, 262144.0\]          |
|        30        | \[-524288.0, 524288.0\]          |

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
