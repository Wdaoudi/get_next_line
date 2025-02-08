# Get Next Line
<div align="center">
  <img src="https://img.shields.io/badge/norminette-passing-success"/>
  <img src="https://img.shields.io/badge/42-project-000000"/>
</div>

## 💡 About
> A C function that reads a line from a file descriptor, making file reading operations more convenient.

This project implements a function that reads text from a file descriptor line by line. It's particularly useful for parsing files, handling input streams, and processing text data sequentially. The project introduces the concept of static variables in C and teaches efficient memory management.

## 🛠️ Usage
### Requirements
- GCC compiler
- C Language
- Make

### Instructions
**1. Compiling**
```shell
$ git clone https://github.com/Wdaoudi/get_next_line
$ cd get_next_line
$ cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

**2. Using it**
```c
#include "get_next_line.h"

int main()
{
    int fd = open("example.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 📋 Features

| Feature | Description |
|---------|-------------|
| Line Reading | Reads text line by line from a file descriptor |
| Memory Management | Efficient memory allocation and deallocation |
| Static Variables | Uses static variables to maintain state between function calls |
| Buffer Size Control | Customizable buffer size via compilation flag |
| Error Handling | Robust error checking and handling |

## 📊 Testing
```shell
# Compile with different buffer sizes
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 *.c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=10000000 *.c
```

Example usage:
```c
int fd1 = open("test1.txt", O_RDONLY);
int fd2 = open("test2.txt", O_RDONLY);

char *line1 = get_next_line(fd1); // Read from first file
char *line2 = get_next_line(fd2); // Read from second file
```

## 💫 Bonus Features
- Handles multiple file descriptors simultaneously
- Manages file descriptors from 0 to 1024
- Uses only one static variable
- Complete memory leak-free implementation

The bonus part includes additional files:
- get_next_line_bonus.c
- get_next_line_bonus.h
- get_next_line_utils_bonus.c
