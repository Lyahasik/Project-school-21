# ft_printf

The first project at the Department of Algorithms and Artificial Intelligence in 42 schools. This project requires the creation of a function that works similarly to the Printf function of the Stdio library.
This function fully supports the format specifiers of the original function. General structure for printf:

%[flags][width][precision][modifiers][conversion type]

The [`ft_printf.en.pdf`](/ft_printf/ft_printf.en.pdf) file contains the technical documentation of the project.

## How to use on MACos
 
 1. move the contents of the folder Realization to your project.
 2. include the header “ft_printf.h” in your project and use the ft_printf function
 3. run the command `make -C path`
 4. compile your code using the following commands:
```
gcc -I path -c yourSource.c
gcc -o yourExecutable ft_printf.o yourSource.o
```
