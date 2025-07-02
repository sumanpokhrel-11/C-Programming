// In calculator.h, declare function prototypes for add(int a, int b), subtract(int a, int b), multiply(int a, int b).

#ifndef CALCULATOR_H
#define CALCULATOR_H

int add(int a, int b);

int subtract(int a, int b);

int multiply(int a, int b);

#endif
/*
To compile a program using this header, you need to:
1. Implement the functions declared here in a .c or .cpp file (e.g., calculator.c).
2. Include this header in your main source file (e.g., #include "calculator.h").
3. Compile both the implementation and main file together. For example:

gcc main.c calculator.c -o calculator

Replace main.c and calculator.c with your actual source file names.
*/