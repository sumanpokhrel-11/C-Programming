// Create three files: calculator.h, calculator.c, and main_calc.c.

// In calculator.h, declare function prototypes for add(int a, int b), subtract(int a, int b), multiply(int a, int b).

// In calculator.c, implement these functions.

// In main_calc.c, include calculator.h and use the functions to perform some calculations and print results.

// Compile these files using gcc and demonstrate the full compilation flow.


// Using the calculator.h, calculator.c, and main_calc.c files, create a Makefile that:

// Compiles calculator.c into calculator.o.

// Compiles main_calc.c into main_calc.o (making sure to include the calculator.h dependency).

// Links calculator.o and main_calc.o to create an executable named calc_app.

// Includes a clean target to remove .o files and calc_app.

// Test your Makefile by running make and make clean.

#include <stdio.h>
#include "calculator.h"

int main() {
    int a, b;
    a = 10;
    b = 5;
    printf("The sum is: %d\n", add(a,b));
    printf("The subtraction is: %d\n", subtract(a,b));
    printf("The multiple is: %d\n", multiply(a,b));
    return 0;
}