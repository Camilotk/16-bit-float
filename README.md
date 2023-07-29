# IEEE 754 Float Implementation

This project provides a basic implementation of IEEE 754-2019 floating-point representation for 16-bit floats. The implementation includes functions to encode and decode floating-point values, inspect the internal binary representation, and a simple REPL (Read-Eval-Print Loop) to interact with the functionalities.

## Introduction

The IEEE 754 standard defines the format for representing floating-point numbers in computers. This project provides a simplified implementation for 16-bit floats using 1 bit for the sign, 5 bits for the power value (exponent), and 10 bits for the mantissa (fractional part). Although this implementation does not cover all rounding strategies, it serves as an educational example of how floating-point numbers work in memory.

## How it Works

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
