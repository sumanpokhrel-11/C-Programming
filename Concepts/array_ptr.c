// Write a function that takes a 1D integer array and its size, and calculates the sum of all its elements using pointer arithmetic.

#include <stdio.h>

int array_sum(int arr[], int arr_len) {
    int *ptr = arr;
    int sum = 0;
    for(int i= 0; i<arr_len; i++) {
        sum+= *(ptr + i);
    }
    return sum;
}

int main() {
    int my_num[] = {1, 5, 52, 62, 34};
    int arr_len = sizeof(my_num)/sizeof(my_num[0]);
    int sum = array_sum(my_num, arr_len);
    printf("The sum of the numbers in array is: %d\n", sum);
    return 0;
}