// Create three files: calculator.h, calculator.c, and main_calc.c.

// In calculator.h, declare function prototypes for add(int a, int b), subtract(int a, int b), multiply(int a, int b).

// In calculator.c, implement these functions.

// In main_calc.c, include calculator.h and use the functions to perform some calculations and print results.

// Compile these files using gcc and demonstrate the full compilation flow.

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