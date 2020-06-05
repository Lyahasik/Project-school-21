# Get_next_line
This project includes the creation of a function that can extract information from several file descriptors line by line,
allowing you to read only pieces of data of a certain size.

```
int get_next_line (int const fd, char ** line)
  1. fd - file descriptor for reading
  2. line - pointer to char *, which stores the string from fd
```

The function will return 1 if the line was read, 0 if the reading is completed, or -1 if an error occurred.

The [`get_next_line.en.pdf`](/get_next_line/get_next_line.en.pdf) file contains the technical documentation of the project.

## How to use on MACos
 
 1. move the contents of the folder Realization to your project.
 2. include the header “get_next_line.h” in your project and use the get_next_line function
 3. run the `make -C path/libft` command to create the **"libft.a"** library
 4. compile your code using the following commands:
```
gcc -I path/libft/includes/ -c get_next_line.c
gcc -I path/libft/includes/ -c yourSource.c
gcc -o yourExecutable get_next_line.o yourSource.o -L /libft/
```
