// Create an integer array. Use a pointer to iterate through the array and print each element.

#include <stdio.h>

int main() {
    int arr[6]= {1, 3, 4, 5, 6, 7};
    // int *ptr = &arr;
    int *ptr = arr;
    for(int i= 0; i<6; i++) {
        printf("%d\n", *(ptr + i));
    }
    return 0;
}