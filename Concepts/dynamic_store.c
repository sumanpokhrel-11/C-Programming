// Write a program that asks the user for the number of integers they want to store.

// Dynamically allocate an array of that size using malloc.

// Read the integers from the user and store them in the dynamically allocated array.

// Print the elements of the array.

// Before exiting, free the allocated memory.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int len;
    printf("Enter the number of Integers you want to store: ");
    scanf("%d", &len);

    int *value;
    value = (int *)malloc(len * sizeof(int));
    if(value ==NULL) {
        printf("Memory Allocation Failed!");
    }
    int integer;
    for(int i= 0; i<len; i++) {
        printf("\nEnter Integer to Store: ");
        scanf("%d", &integer);
        value[i] = integer;

    }
    printf("The stored value is:\n");
    for(int i= 0; i<len; i++) {
        printf("%d\n", value[i]);

    }
    free(value);
    if (value ==NULL) {
        printf("The memory is freed!");
    }
    return 0;
}