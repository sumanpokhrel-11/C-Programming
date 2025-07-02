# Dynamic Memory Management

Dynamic memory management allows you to allocate memory during program execution (runtime) from the heap. This is crucial for managing data structures where the size is not known beforehand.

## `malloc`, `calloc`, `realloc`, `free`

These functions are part of `<stdlib.h>`.

- **`malloc(size_t size)`**: Allocates `size` bytes of uninitialized memory. Returns a `void*` pointer to the allocated memory, or `NULL` if allocation fails.

    ```c
    int *arr = (int *)malloc(5 * sizeof(int)); // Allocate space for 5 integers
    if (arr == NULL) {
        // Handle error
    }
    // arr[0] to arr[4] are now accessible
    ```

- **`calloc(size_t num, size_t size)`**: Allocates memory for `num` elements, each of `size` bytes, and initializes all allocated bytes to zero. Returns a `void*` pointer.

    ```c
    int *arr = (int *)calloc(5, sizeof(int)); // Allocate and initialize to 0
    ```

- **`realloc(void *ptr, size_t new_size)`**: Changes the size of the memory block pointed to by `ptr` to `new_size` bytes. The contents will be preserved up to the lesser of the old and new sizes. Returns a `void*` pointer to the new memory block (which might be at a different address), or `NULL` if allocation fails.

    ```c
    // Assume arr was previously allocated with malloc
    int *newArr = (int *)realloc(arr, 10 * sizeof(int)); // Resize to 10 integers
    if (newArr == NULL) {
        // Handle error
    } else {
        arr = newArr; // Update the pointer if realloc was successful
    }
    ```

- **`free(void *ptr)`**: Deallocates the memory block pointed to by `ptr`. It's crucial to free memory once it's no longer needed to prevent memory leaks.

    ```c
    free(arr);
    arr = NULL; // Good practice to set pointer to NULL after freeing
    ```

---

## Difference Between Stack and Heap

| Feature      | Stack                                             | Heap                                  |
|--------------|---------------------------------------------------|---------------------------------------|
| Allocation   | Automatic (for local variables, function calls)   | Manual (via malloc, calloc, etc.)     |
| Lifetime     | Tied to function scope, deallocated automatically | Until explicitly freed or program ends|
| Speed        | Very fast                                         | Slower due to overhead of managing memory |
| Size Limit   | Relatively small, limited by OS                   | Much larger, limited by physical memory |
| Access       | Direct                                            | Via pointers                          |

---

## Practice: Allocating and Freeing Memory Properly

```c
#include <stdio.h>
#include <stdlib.h> // For malloc, free

int main() {
    int *data;
    int numElements = 5;

    // Allocate memory for 5 integers
    data = (int *)malloc(numElements * sizeof(int));

    // Check if allocation was successful
    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Indicate an error
    }

    // Use the allocated memory
    for (int i = 0; i < numElements; i++) {
        data[i] = (i + 1) * 10;
        printf("data[%d] = %d\n", i, data[i]);
    }

    // Resize the memory block
    int newNumElements = 8;
    int *temp = (int *)realloc(data, newNumElements * sizeof(int));

    if (temp == NULL) {
        printf("Memory reallocation failed!\n");
        free(data); // Free original memory before exiting
        return 1;
    } else {
        data = temp; // Update data pointer if realloc successful
        printf("\nMemory reallocated successfully.\n");
        for (int i = numElements; i < newNumElements; i++) {
            data[i] = (i + 1) * 10; // Initialize new elements
        }
        for (int i = 0; i < newNumElements; i++) {
            printf("data[%d] = %d\n", i, data[i]);
        }
    }

    // Free the allocated memory
    free(data);
    data = NULL; // Good practice to prevent dangling pointers

    printf("\nMemory freed successfully.\n");

    return 0;
}
```

---

## ⚠️ Common Mistakes: Memory Leaks, Double Frees, Accessing Freed Memory

- **Memory Leaks**: Forgetting to free allocated memory. This leads to your program consuming more and more memory, eventually crashing.
- **Double Frees**: Calling `free()` on the same memory block twice. This leads to undefined behavior and can crash your program.
- **Accessing Freed Memory (Dangling Pointers)**: Attempting to use memory after it has been freed. The memory might have been reallocated for something else, leading to unpredictable results or crashes. Always set pointers to `NULL` after freeing them.

