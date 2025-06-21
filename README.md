# Top C Programming Resources

## 🏆 1. Harvard's CS50 (Introduction to Computer Science)
- **[CS50 on edX](https://www.edx.org/course/cs50s-introduction-to-computer-science)**
- *Taught by David Malan, known for accessible, engaging teaching.*
- Starts in C, then transitions to Python, SQL, and more.
- Emphasizes memory management, pointers, and data structures early.
- Interactive problem sets simulate real-world scenarios (e.g., image filters, spell checkers).

**Best for:**  
- Understanding why C matters, not just how to code in it.  
- Anyone seeking a strong systems-level foundation.

---

## 📘 2. Learn-C.org (Interactive Online Platform)
- **[Learn-C.org](https://www.learn-c.org/)**
- In-browser C compiler — no setup needed.
- Covers basics: types, pointers, structs, file I/O, etc.
- Interactive, bite-sized examples.

**Best for:**  
- Rapid, hands-on experimentation.  
- Reinforcing core syntax and concepts.

---

## 🧰 3. MIT OpenCourseWare – "Introduction to C and C++"
- **[MIT 18.S997 (YouTube)](https://www.youtube.com/playlist?list=PLUl4u3cNGP63WbdFxL8giv4yhgdMGaZNA)**
- Deep dives into memory layout, pointers, function stacks, and more.
- Taught by MIT faculty with a technical but clear style.

**Best for:**  
- Learners wanting depth (e.g., segmentation faults, malloc internals).  
- Those planning to move into OS or embedded work.

---

## 📦 4. Stanford CS107 Lectures (Systems Programming)
- **[CS107 YouTube Lectures](https://www.youtube.com/playlist?list=PLoCMsyE1cvdWKsLVyf6c5pM1hQX0aQn7R)**
- Focuses on low-level programming, C, memory, and assembly.
- Covers debugging, memory models, tools like gdb, valgrind.

**Best for:**  
- Transitioning from high-level languages to thinking about memory and efficiency.

---

## 🛠️ 5. Google's C++ Class (with C foundations)
- **[Google C++ Class](https://developers.google.com/edu/c++)**
- While focused on C++, initial lessons are a great primer for C programmers.
- Explains memory, pointers, stack vs heap.
- Excellent for procedural to object-oriented transitions.

---

## 🔍 Suggested Progression

1. Start with **Learn-C.org** for basic syntax.
2. Take **CS50** or **MIT OCW** to explore structured thinking and memory.
3. Watch **CS107 lectures** for deeper systems understanding.
4. Use **HackerRank / LeetCode** in C for practical problem-solving.

---

# Projects

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

## 🛠 Tools & Practice

| Tool                           | Use                                               |
|---------------------------------|---------------------------------------------------|
| `gcc -Wall -Wextra -pedantic`   | Compile with warnings to catch bugs early         |
| `valgrind ./program`            | Check for memory leaks                            |
| `gdb` and `lldb`                | Debug segmentation faults, step through execution |
| `make`                          | Automate building multi-file projects             |
