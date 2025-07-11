# 📄 get_next_line

## 📌 Description

`get_next_line` is a function that reads from a file descriptor and returns the next line of text each time it is called. It handles input line by line, including newline characters, until reaching the end of the file or an error.

This project focuses on file reading, buffer management, memory handling, and maintaining state between function calls—all in pure C.

---

## 🛠️ Skills Developed

- File I/O using `read()`
- Static variables to preserve function state
- Dynamic memory management (`malloc`, `free`)
- String manipulation without standard library functions
- Buffer-based reading and line reconstruction
- Handling edge cases (e.g. EOF, multiple file descriptors)

---

## ⚙️ Function Prototype

```c
char *get_next_line(int fd);
