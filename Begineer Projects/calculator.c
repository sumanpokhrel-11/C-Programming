#include <stdio.h>


float sum(float x, float y){
    return x + y;
}
float subtract(float x, float y){
    return x - y;
}
float multiply(float x, float y){
    return x * y;
}
float divide(float x, float y){
    return  x / y;
}

int main() {
    printf("Welcome to my Calculator\n"); 
    float y;
    float x;
    char func;
    float result = 0.0;

    printf("Enter first number: ");
    scanf("%f", &x);


    while (1){
        printf("\n Enter second number: ");
        scanf("%f", &y);

        // Consume the leftover newline character after reading 'y'
        while (getchar() != '\n' && getchar() != EOF); // Clear input buffer

        printf("\n Enter the operations you want to perform : ['+', '-', '*', '/'] : ");
        func = getchar(); // Read a single character directly

        // Consume any remaining newline after reading 'func' if user presses enter
        while (getchar() != '\n' && getchar() != EOF);


        if (func == '/' && y == 0) { // Corrected condition: only an error if func is '/' AND y is 0
            printf("Division by zero error. Please enter value greater than 0. ");
        }
        else {
            break; // If no division by zero error, exit the loop.
        }
    }

    switch (func) {
        case '+':
            result = sum(x, y);
            break;
        case '-':
            result = subtract(x, y);
            break;
        case '*':
            result = multiply(x, y);
            break;
        case '/':
            result = divide(x, y);
            break;
        default:
            printf("Enter a valid operation: ['+', '-', '*', '/'] \n"); // Added newline
            // You might want to handle this more gracefully, e.g., by looping back or exiting.
            return 1; // Indicate an error
    }
    printf("The result is : %f\n", result); // Added newline for better output

    return 0;
}