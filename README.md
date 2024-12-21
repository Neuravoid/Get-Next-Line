# Get Next Line

**Get Next Line** is a project included in the curriculum of 42 schools. This project aims to develop a C function that allows reading data line by line from a file descriptor.

## Project Objective

The primary goal of this project is to implement a `get_next_line` function with the following features:

- **Line Reading**: The function reads one line at a time from a file descriptor and returns it.
- **Memory Management**: Dynamic memory allocation and management are handled using `malloc` and `free`.
- **System Calls**: The `read` system call is used to read data from the file.
- **Static Variables**: The function uses static variables to store leftover data from the previous call.

## Function Prototype

```c
char *get_next_line(int fd);
```

- `fd`: The file descriptor to read from.
- **Return Value**: A pointer to a character string containing the read line. Returns `NULL` if the end of the file is reached or an error occurs.

## Usage

The `get_next_line` function can be called in a loop to read one line at a time until the end of the file:

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    // Process the line
    free(line);
}
close(fd);
```

## Compilation

The function can be compiled with the `BUFFER_SIZE` macro defined at compile time to test with different buffer sizes:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c -o gnl
```

## Important Notes

- **Buffer Size**: The `BUFFER_SIZE` value determines the buffer size used in `read` calls and can impact performance.
- **Multiple File Descriptors**: The function should be designed to handle multiple file descriptors simultaneously.
- **Memory Leaks**: Since dynamic memory allocation is used, it is crucial to free each read line to prevent memory leaks.
