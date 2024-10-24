# Pipex - Handling UNIX Pipes

## Project Overview

**Pipex** is a project that explores the detailed mechanics of UNIX pipes by recreating the functionality of shell pipelines. This project focuses on replicating the behavior of the shell command that takes two commands and connects them via a pipe, redirecting input and output through specified files.

By working on this project, I gained valuable experience with inter-process communication, process management, and the use of UNIX system calls such as `pipe()`, `fork()`, and `execve()`.

---

## Key Features

- **Program Name**: `pipex`
- **Usage**: 
  ```bash
  ./pipex file1 cmd1 cmd2 file2
< file1 cmd1 | cmd2 > file2

## Skills Demonstrated

- UNIX System Calls: Gained experience with key system calls such as pipe(), fork(), execve(), and dup2(), which are fundamental to UNIX inter-process communication.
- Process Management: Learned how to create and manage multiple processes using fork() and control the flow of data between them using pipes.
- Error Handling: Implemented robust error handling to ensure the program behaves correctly under a variety of edge cases and invalid inputs.
- Memory Management: Ensured that all memory allocations are properly handled to prevent memory leaks.
