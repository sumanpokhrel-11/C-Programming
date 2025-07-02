## Arrays

Arrays are collections of elements of the same data type stored in contiguous memory locations.

### Static vs. Dynamic Arrays

- **Static Arrays:** Declared with a fixed size at compile time. Their size cannot be changed during runtime. They are typically allocated on the stack.

    ```c
    int staticArray[5]; // An array of 5 integers
    ```

- **Dynamic Arrays:** Their size can be determined and changed at runtime. They are allocated on the heap using functions like `malloc`, `calloc`, or `realloc`. We'll cover this in more detail under Dynamic Memory Management.

    ```c
    int *dynamicArray;
    // later: dynamicArray = (int *)malloc(5 * sizeof(int));
    ```

### Pointer vs. Array Relationships

In C, array names often decay into pointers to their first element. This is a crucial concept.

```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // arr decays to a pointer to its first element

    printf("arr[0] = %d\n", arr[0]);
    printf("*ptr = %d\n", *ptr);        // Same as arr[0]

    printf("arr[2] = %d\n", arr[2]);
    printf("*(ptr + 2) = %d\n", *(ptr + 2)); // Pointer arithmetic to access elements

    // Both arr and ptr can be used with array indexing,
    // but arr is a constant pointer, ptr is a variable pointer.
    // ptr++; // Valid
    // arr++; // Invalid - array name is a constant pointer

    return 0;
}
```

### Multidimensional Arrays

Arrays of arrays. The most common is a 2D array (matrix).

```c
#include <stdio.h>

int main() {
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // Accessing elements
    printf("Element at [0][1]: %d\n", matrix[0][1]); // Output: 2
    printf("Element at [1][2]: %d\n", matrix[1][2]); // Output: 6

    // Iterating through a 2D array
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```
