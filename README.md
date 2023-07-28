# IEEE 754 float implementation 

This project aims implement a [IEEE 754 - 2019](https://standards.ieee.org/ieee/754/6210/) basic implementation for floats.
For matter of simplicity will use 16 bit as size (1 for signal, 5 for power value, 10 for mantissa). It will not implement
full rounding strategies described, only a basic representation for float with simple round() function.

The main objective is just make it as example of how floats works in memory in C (and other programming languages).

## Project Structure
```
.
├── Makefile
├── README.md
├── main.c
├── src
│   ├── problem.c
│   └── problem.h
└── tests
    └── test_problem.c

2 directories, 6 files
```

- main.c: Main function
- src/*.c, *.h: Project files
- tests/*.c: Unit Tests
