## 🧱 Beginner Projects

*Goal: Get comfortable with syntax, flow control, functions, memory basics*

1. **Guess the Number Game**  
    - Generate a random number between 1–100  
    - Loop until the user guesses correctly  
    - Use `rand()`, `scanf()`, and `if/else`

2. **Basic Calculator**  
    - Accept two operands and an operator (`+`, `-`, `*`, `/`)  
    - Use `switch` statements  
    - Handle division-by-zero errors

3. **Temperature Converter**  
    - Convert between Celsius and Fahrenheit  
    - Introduce math functions and float formatting

---

## 📂 Intermediate Projects

*Goal: Understand pointers, structs, arrays, string manipulation, file I/O*

4. **Student Record System**  
    - Define a `struct Student` with fields like name, roll number, grades  
    - Add, search, update, and delete records  
    - Store data in files (`fopen`, `fwrite`, `fread`)

5. **Tic Tac Toe (2-Player)**  
    - Use 2D arrays and functions  
    - Display the board in the console  
    - Check for a winning condition after each move

6. **Word Counter**  
    - Read a `.txt` file and count words, lines, and characters  
    - Practice string handling and file reading

---

## 🧠 Advanced Projects

*Goal: Dynamic memory, manual data structures, memory-safe coding*

7. **Custom `malloc()` Tracker**  
    - Wrap `malloc()` and `free()` to log allocation sizes  
    - Report total memory allocated and freed  
    - Learn memory diagnostics and pointer management

8. **Simple Shell (`mysh`)**  
    - Take user commands via `getline()` or `scanf()`  
    - Use `fork()`, `execvp()`, and `wait()` to execute commands  
    - (Bonus) Build tab-completion and command history

9. **Mini Compiler for Arithmetic Expressions**  
    - Parse strings like `"3 + (4 * 5)"`  
    - Convert to postfix using a stack  
    - Evaluate using a stack or recursive descent

---

### 🛠 Tools & Practice

| Tool                           | Use                                               |
|---------------------------------|---------------------------------------------------|
| `gcc -Wall -Wextra -pedantic`   | Compile with warnings to catch bugs early         |
| `valgrind ./program`            | Check for memory leaks                            |
| `gdb` and `lldb`                | Debug segmentation faults, step through execution |
| `make`                          | Automate building multi-file projects             |
