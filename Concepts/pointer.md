# 1. Pointers

Pointers are fundamental to C programming. They are variables that store memory addresses.

## Concepts

### Declaration

Declaring a pointer involves specifying the data type of the variable it will point to, followed by an asterisk (`*`):

```c
int *ptr;      // ptr is a pointer to an integer
char *charPtr; // charPtr is a pointer to a character
```

### Dereferencing

Dereferencing is the process of accessing the value stored at the memory address held by a pointer. Use the asterisk (`*`) operator for dereferencing:

```c
int x = 10;
int *ptr = &x; // ptr now holds the address of x
printf("Value of x: %d\n", *ptr); // Dereference ptr to get the value of x
```

### Pointer Arithmetic

You can perform arithmetic operations on pointers. When you add or subtract an integer from a pointer, it moves the pointer by a multiple of the size of the data type it points to:

```c
int arr[] = {10, 20, 30, 40, 50};
int *p = arr; // p points to the first element (arr[0])

printf("First element: %d\n", *p);         // Output: 10
printf("Second element: %d\n", *(p + 1));  // Moves to the next integer, output: 20
```

## Practice: Passing Pointers to Functions & Pointer to Pointer

### Example: Swapping Two Numbers Using Pointers

```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1 = 5;
    int num2 = 10;

    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2); // Pass addresses of num1 and num2
    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
```

### Example: Pointer to Pointer

A pointer to a pointer stores the address of another pointer.

**Syntax:**
```c
type **pointer_name;
```

**Example:**
```c
int **ptr2;
```
Here, `ptr2` is a pointer to a pointer to an integer.

```c
#include <stdio.h>

int main() {
    int value = 100;
    int *ptr1 = &value;    // ptr1 stores the address of 'value'
    int **ptr2 = &ptr1;    // ptr2 stores the address of 'ptr1'

    printf("Value: %d\n", value);
    printf("Value using ptr1: %d\n", *ptr1);
    printf("Value using ptr2: %d\n", **ptr2); // Dereference twice to get the original value

    printf("Address of value: %p\n", &value);
    printf("Address stored in ptr1: %p\n", ptr1);
    printf("Address of ptr1: %p\n", &ptr1);
    printf("Address stored in ptr2: %p\n", ptr2);

    return 0;
}
```
