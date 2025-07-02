# Structs

Structs (structures) allow you to group variables of different data types under a single name.

---

## Declaration, Initialization, Nested Structs

### Declaration

```c
struct Person {
    char name[50];
    int age;
    float height;
};
```

### Initialization

```c
struct Person p1 = {"Alice", 30, 1.65}; // Direct initialization

struct Person p2;
strcpy(p2.name, "Bob");
p2.age = 25;
p2.height = 1.80;
```

### Nested Structs

A struct can contain another struct.

```c
struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    char name[50];
    int rollNo;
    struct Date dob; // Nested struct
};

struct Student s1 = {"Charlie", 101, {15, 8, 2000}};
```

---

## Access via Dot (`.`) and Arrow (`->`) Operators

- **Dot operator (`.`):** Used to access members of a struct variable.

    ```c
    struct Person p1 = {"Alice", 30, 1.65};
    printf("Name: %s, Age: %d\n", p1.name, p1.age);
    ```

- **Arrow operator (`->`):** Used to access members of a struct when you have a pointer to a struct.

    ```c
    struct Person p1 = {"Alice", 30, 1.65};
    struct Person *ptrP1 = &p1;

    printf("Name (via pointer): %s, Age (via pointer): %d\n", ptrP1->name, ptrP1->age);
    // This is equivalent to (*ptrP1).name and (*ptrP1).age
    ```

---

## Structs with Pointers

Pointers to structs are very common, especially when working with dynamic memory or linked data structures.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point {
    int x;
    int y;
};

int main() {
    // Allocate a Point struct dynamically
    struct Point *myPoint = (struct Point *)malloc(sizeof(struct Point));

    if (myPoint == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Access members using the arrow operator
    myPoint->x = 10;
    myPoint->y = 20;

    printf("My Point: (%d, %d)\n", myPoint->x, myPoint->y);

    free(myPoint);
    myPoint = NULL;

    return 0;
}
```