
// Write a function void increment(int *num) that takes a pointer to an integer and increments the value it points to by 10.

#include <stdio.h>

void increment(int *num){
    *num +=10;
}

int main() {
    int point = 10;
    printf("The value of point is: %d\n", point);
    increment(&point);
    printf("The value after increment is : %d\n", point);
    return 0;


}