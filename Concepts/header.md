# Header Files & `-I` Includes

Header files (`.h` files) are essential for organizing C code and promoting modularity. They contain declarations (function prototypes, struct definitions, global variable declarations) but not their implementations.

## Creating `.h` and `.c` Files

Suppose we have a utility for string operations.

### `string_utils.h`

```c
#ifndef STRING_UTILS_H
#define STRING_UTILS_H

// Function prototype for string concatenation
char* custom_strcat(char* dest, const char* src);

// Function prototype for string length
int custom_strlen(const char* str);

#endif
```

### `string_utils.c`

```c
#include "string_utils.h" // Include our own header
#include <string.h>       // For strlen, strcpy if needed internally
#include <stdlib.h>       // For malloc if needed

// Implementation of custom_strcat
char* custom_strcat(char* dest, const char* src) {
    // In a real scenario, you'd ensure dest has enough space
    // For simplicity, this assumes dest is large enough or dynamically allocated
    strcpy(dest + strlen(dest), src);
    return dest;
}

// Implementation of custom_strlen
int custom_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
```

### `main.c`

```c
#include <stdio.h>
#include "string_utils.h" // Include our custom header

int main() {
    char buffer[100] = "Hello, ";
    custom_strcat(buffer, "World!");
    printf("%s\n", buffer);

    printf("Length of 'Hello': %d\n", custom_strlen("Hello"));

    return 0;
}
```

## Using `#include` and Compiling with `gcc -I`

- `#include "filename.h"`: Used for user-defined header files; the preprocessor looks in the current directory first, then standard include paths.
- `#include <filename.h>`: Used for standard library header files; the preprocessor looks only in standard include paths.

### Compiling the Example

You can compile `string_utils.c` and `main.c` separately and then link them, or compile them together:

```sh
gcc -c string_utils.c      # Compiles string_utils.c into string_utils.o
gcc -c main.c              # Compiles main.c into main.o
gcc string_utils.o main.o -o my_program  # Links the object files
```

#### Using `-I` for Custom Include Paths

If your `string_utils.h` is in a subdirectory like `include/`, compile `main.c` using `-I`:

```sh
gcc -I./include -c main.c
```

Then link as before:

```sh
gcc string_utils.o main.o -o my_program
```

## Compilation Flow: Preprocessing → Compiling → Linking

1. **Preprocessing**: Handles directives like `#include`, `#define`, `#ifdef`, etc. The preprocessor effectively copies the content of header files into the `.c` files. The output is typically a `.i` (intermediate) file.
2. **Compiling**: The compiler takes the preprocessed `.i` file and translates it into assembly code, then into machine code (object code). The output is an `.o` (object) file for each `.c` file. This stage checks for syntax errors, type checking, etc.
3. **Linking**: The linker combines all the object files (`.o`) and any necessary library files into a single executable program. It resolves references to functions and variables defined in other files or libraries.

---

## Example Project Structure

```
project/
├── include/
│   └── string_utils.h
├── src/
│   └── string_utils.c
├── main.c
```

### `string_utils.h`

```c
#ifndef STRING_UTILS_H
#define STRING_UTILS_H

// Function prototype for string concatenation
char* custom_strcat(char* dest, const char* src);

// Function prototype for string length
int custom_strlen(const char* str);

#endif
```

### `string_utils.c`

```c
#include "string_utils.h"
#include <string.h>
#include <stdlib.h>

// Implementation of custom_strcat
char* custom_strcat(char* dest, const char* src) {
    strcpy(dest + strlen(dest), src);
    return dest;
}

// Implementation of custom_strlen
int custom_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
```

### `main.c`

```c
#include <stdio.h>
#include "string_utils.h"

int main() {
    char buffer[100] = "Hello, ";
    custom_strcat(buffer, "World!");
    printf("%s\n", buffer);

    printf("Length of 'Hello': %d\n", custom_strlen("Hello"));

    return 0;
}
```

## Compiling the Project

If your header file is in the `include/` directory and source files are in `src/`, compile with:

```sh
gcc -I./include -c src/string_utils.c
gcc -I./include -c main.c
gcc string_utils.o main.o -o my_program
```

- `-I./include` tells the compiler to look for header files in the `include/` directory.
- Compile each `.c` file to an object file (`.o`), then link them together.

## Compilation Flow

1. **Preprocessing**: Handles `#include`, `#define`, etc.
2. **Compiling**: Converts preprocessed code to object files.
3. **Linking**: Combines object files into an executable.
