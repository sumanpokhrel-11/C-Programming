# Time Complexity Basics

Time complexity describes how the runtime of an algorithm grows as the input size (`n`) increases. It's expressed using **Big-O notation** (`O(...)`). Big-O focuses on the worst-case scenario and ignores constant factors and lower-order terms.

## Big-O Notation

- **O(1) (Constant Time):** The time taken is independent of the input size.
- **O(log n) (Logarithmic Time):** The time taken grows logarithmically with the input size. Common in algorithms that divide the problem in half with each step.
- **O(n) (Linear Time):** The time taken grows directly proportional to the input size.
- **O(n²) (Quadratic Time):** The time taken grows as the square of the input size. Often seen with nested loops.

---

## Simple Code Examples

### O(1) (Array Access)

Accessing an element at a specific index in an array.

```c
int arr[] = {1, 2, 3, 4, 5};
int value = arr[2]; // O(1) - direct access
```

---

### O(n) (Linear Search)

Searching for an element by iterating through each element in an array.

```c
// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) { // Loop runs 'n' times
        if (arr[i] == target) {
            return i; // Found
        }
    }
    return -1; // Not found
}
```

---

### O(n²) (Nested Loops)

Algorithms with nested loops, where the inner loop runs 'n' times for each iteration of the outer loop.

```c
// Example: Simple bubble sort (demonstrates O(n^2))
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // Outer loop runs 'n' times
        for (int j = 0; j < n - i - 1; j++) { // Inner loop runs roughly 'n' times
            if (arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
```

---

### O(log n) (Binary Search)

Requires a sorted array. It repeatedly divides the search interval in half.

```c
// Function to perform binary search
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid overflow
        if (arr[mid] == target) {
            return mid; // Found
        } else if (arr[mid] < target) {
            low = mid + 1; // Discard left half
        } else {
            high = mid - 1; // Discard right half
        }
    }
    return -1; // Not found
}
```