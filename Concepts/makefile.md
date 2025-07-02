# Makefiles

Makefiles are used to automate the compilation process, especially for larger projects with many source files and dependencies. The `make` utility reads a `Makefile` (or `makefile`) to determine how to build a target.

## Write a Simple Makefile to Automate Compilation

Continuing with our `string_utils` example:

```makefile
# Makefile

# Define variables
CC = gcc
CFLAGS = -Wall -g        # -Wall for warnings, -g for debugging info
INC_DIR = .              # Our include directory is the current directory

# Define targets
all: my_program

my_program: main.o string_utils.o
    $(CC) $(CFLAGS) main.o string_utils.o -o my_program

main.o: main.c string_utils.h
    $(CC) $(CFLAGS) -I$(INC_DIR) -c main.c

string_utils.o: string_utils.c string_utils.h
    $(CC) $(CFLAGS) -c string_utils.c

clean:
    rm -f *.o my_program
```

## Concepts: Targets, Dependencies, gcc Commands

- **Targets:** What you want to build (e.g., `my_program`, `main.o`, `clean`). The first target is the default one (usually `all`).
- **Dependencies:** The files or targets that must exist or be up-to-date before the target can be built. For `my_program`, `main.o` and `string_utils.o` are dependencies. For `main.o`, `main.c` and `string_utils.h` are dependencies.
- **Commands:** The shell commands to execute to build the target. These lines must start with a **tab character** (not spaces).

## How to use

1. Save the `Makefile` in the same directory as your `.c` and `.h` files.
2. Open your terminal in that directory.
3. Run `make` (this will build the `all` target, which builds `my_program`).
4. Run `make clean` to remove object files and the executable.
